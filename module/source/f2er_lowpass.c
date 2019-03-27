#include "../include/f2er_lowpass.h"
#include "stdint.h"
#include "string.h"

static float_t f2er_low_pass_ops_filtered(struct f2er *f2er, float_t input)
{
    uint16_t i=0;
    float_t temp=0;
    //if a0=1 the output y could be expressed by
    // y(n)=[bo*x(n)+b1*x(n-1)+.....]-[a1*y(n-1)+a2*y(n-2)]
    temp = input;
    f2er->wiir[0][0]= temp  - (
                (f2er->a[1]) * (f2er->wiir[0][1])+
                (f2er->a[2]) * (f2er->wiir[0][2])
                );

    temp =  (f2er->b[0])   * (f2er->wiir[0][0]) +
            (f2er->b[1]) * (f2er->wiir[0][1]) +
            (f2er->b[2]) * (f2er->wiir[0][2]) ;

    for (i=2;i>0;i--)
        f2er->wiir[0][i]=f2er->wiir[0][i-1];

    return temp;

}

static struct f2er_ops f2er_ops = {
    .filtered = f2er_low_pass_ops_filtered,
};


void f2er_low_pass_init(struct f2er_low_pass *f2er_low_pass)
{
    f2er_init(&f2er_low_pass->f2er);
    f2er_low_pass->f2er.ops=&f2er_ops;
}

