#include "f1er_lowpass.h"
#include "stdint.h"
#include <string.h>


static float_t f1er_low_pass_ops_filtered(struct f1er *f1er, float_t input)
{

    uint16_t i=0;
    //if a0=1 the output y could be expressed by
    // y(n)=[bo*x(n)+b1*x(n-1)+.....]-[a1*y(n-1)+a2*y(n-2)]
    for (i=1;i>0;i--)
        f1er->yiir[i]=f1er->yiir[i-1];
    f1er->yiir[0]=f1er->b[0] * input - (f1er->a[1] * f1er->yiir[1]);

    return f1er->yiir[0];


}

static struct f1er_ops f1er_ops = {
    .filtered = f1er_low_pass_ops_filtered,
};


void f1er_low_pass_init(struct f1er_low_pass *f1er_low_pass)
{
    f1er_init(&f1er_low_pass->f1er);
    f1er_low_pass->f1er.ops=&f1er_ops;
}

