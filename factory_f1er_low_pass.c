#include "stdio.h"
#include "factory_f1er_low_pass.h"
#include "f1er_lowpass.h"
#include "stdlib.h"
#include "math.h"
#include "float.h"
#include <complex.h>
#include "f1er.h"



static struct f1er * factory_f1er_low_pass_ops_create(struct factory_f1er *factory_f1er)
{
    struct f1er_low_pass * f1;
    struct f1er * filter;
    float_t fc=0;
    float_t fs=0;
    f1 = malloc(sizeof(*f1));
    f1er_low_pass_init(f1);
    fc = factory_f1er->config.fc;
    fs = factory_f1er->config.fs + (float_t)FLT_EPSILON; // To avoid div by 0
    filter = &(f1->f1er);
    filter->b[0]    =(float_t)(1-exp(-2*M_PI*fc*1/fs)); // b0
    filter->b[1]    = 0;
    filter->a[0]    =(float_t)(1); // a0
    filter->a[1]    =(float_t)(-exp(-2*M_PI*fc*1/fs));// a1
    filter->yiir[0]=0;
    filter->yiir[1]=0;
    return &f1->f1er;
}

static struct factory_f1er_ops factory_f1er_ops = {
    .create = factory_f1er_low_pass_ops_create,
};


void factory_f1er_low_pass_init(struct factory_f1er_low_pass *factory_f1er_low_pass)
{
    factory_f1er_init(&factory_f1er_low_pass->factory_f1er);
    factory_f1er_low_pass->factory_f1er.ops = &factory_f1er_ops;
}


t_errors_f1er set_frecuencies_f1er_low_pass_init(struct factory_f1er * factory_f1er,float fc,float fs)
{
    if (fc==0.0)
        return ERROR_FC_ZERO;
    else if (fs==0.0)
        return ERROR_FS_ZERO;
    else if (fs<fc)
        return ERROR_FS_MINOR_FC;
    else
    {
        factory_f1er->config.fc=(float_t)fc;
        factory_f1er->config.fs=(float_t)fs;
        return NO_ERROR;
    }
}
