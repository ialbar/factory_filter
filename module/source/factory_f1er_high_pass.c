#include "factory_f1er_high_pass.h"
#include "stdio.h"
#include "f1er_highpass.h"
#include "stdint.h"
#include "stdlib.h"
#include "math.h"
#include "float.h"
#include <complex.h>



static struct f1er * factory_f1er_high_pass_ops_create(struct factory_f1er *factory_f1er)
{
    struct f1er_high_pass * f1;
    struct f1er * filter;
    uint8_t i=0;
    float_t fc=0;
    float_t fs=0;
    float_t gain_w0=0;
    float complex num_w0,dem_w0;
    float_t w0;
    float_t Tsample;
    float_t b0,b1,a0,a1;
    float_t Kfdt;
    float_t db= (float_t)(1.0/20.0);

    f1 = malloc(sizeof(*f1));
    f1er_high_pass_init(f1);
    fc = factory_f1er->config.fc;
    fs = factory_f1er->config.fs + (float_t)FLT_EPSILON; // To avoid div by 0
    Tsample=1/fs;
    w0= 2*(float_t)M_PI*fc;
    b0=(float_t)(1.0);
    b1=(float_t)(-1.0);
    a0=(float_t)(1.0);
    a1=-expf(-w0*Tsample);
    num_w0=b0*cexpf(I*w0*Tsample)+b1;
    dem_w0=a0*cexpf(I*w0*Tsample)+a1;
    gain_w0=powf(10.0,-3.0*db);
    Kfdt = gain_w0/(cabsf(num_w0/dem_w0));
    filter = &(f1->f1er);
    filter->b[0]    =Kfdt*b0; // b0
    filter->b[1]    =Kfdt*b1;//b1
    filter->a[0]    =(float_t)(1.0); // a0
    filter->a[1]    =(float_t)(-expf(-2*(float_t)M_PI*fc/fs));// a1
    for (i=0;i<=1;i++)
    {
        filter->yiir[i]=(float_t)0.0;
        filter->xiir[i]=(float_t)0.0;
    }
    return &f1->f1er;
}

static struct factory_f1er_ops factory_f1er_ops = {
    .create = factory_f1er_high_pass_ops_create,
};


void factory_f1er_high_pass_init(struct factory_f1er_high_pass *factory_f1er_high_pass)
{
    factory_f1er_init(&factory_f1er_high_pass->factory_f1er);
    factory_f1er_high_pass->factory_f1er.ops = &factory_f1er_ops;
}

t_errors_f1er set_frecuencies_f1er_high_pass_init(struct factory_f1er * factory_f1er,float fc,float fs)
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
