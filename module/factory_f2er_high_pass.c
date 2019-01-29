#include "stdio.h"
#include "factory_f2er_high_pass.h"
#include "f2er_highpass.h"
#include "stdint.h"
#include "math.h"
#include "float.h"
#include <complex.h>
#include <stdlib.h>

static struct f2er * factory_f2er_high_pass_ops_create(struct factory_f2er *factory_f2er)
{
    struct f2er_high_pass * f2;
    struct f2er * filter;

    float complex num_w0,den_w0;
    float_t gain_w0=0;
    float_t Kfdt=0;
    float complex r1,r2;

    float_t w0;
    float_t Tsample;

    float_t fc;
    float_t fs;
    float_t Q;
    float_t zeta;

    f2 = malloc(sizeof(struct f2er_high_pass *));
    f2er_high_pass_init(f2);

    fc = factory_f2er->config.fc;
    fs = factory_f2er->config.fs + FLT_EPSILON;
    Q = factory_f2er->config.Q;
    zeta = 1/(2*Q);

    w0= (float_t)(2*(float_t)M_PI*fc);
    Tsample=1/fs;

    r1=-((w0/Q)/2) + csqrtf((pow((w0/Q),2) - 4*(w0*w0)))/2;
    r2=-((w0/Q)/2) - csqrtf((pow((w0/Q),2) - 4*(w0*w0)))/2;

    filter = &(f2->f2er);

    filter->a[0]  =1; // a0
    filter->a[1]  =-(cexpf(r1*Tsample)+cexpf(r2*Tsample));
    filter->a[2]  =cexpf(r1*Tsample)*cexpf(r2*Tsample);

    filter->b[0]  =1; // b0
    filter->b[1]  =-2; // b1
    filter->b[2]  =1; // b2
    num_w0=(filter->b[0]*cexpf(I*2*w0*Tsample) + filter->b[1]*cexpf(I*w0*Tsample) + filter->b[2]);
    den_w0=(filter->a[0]*cexpf(I*2*w0*Tsample) + filter->a[1]*cexpf(I*w0*Tsample) + filter->a[2]);
    gain_w0=1/((2*zeta)*sqrtf(1-(zeta*zeta)));
    Kfdt = gain_w0 / cabsf(num_w0/den_w0);
    // bo*z^2-b12*z^1+b2
    filter->b[0]  =1*Kfdt; // b0
    filter->b[1]  =-2*Kfdt; // b1
    filter->b[2]  =1*Kfdt; // b2
    return(&(f2->f2er));
}

static struct factory_f2er_ops factory_f2er_ops = {
    .create = factory_f2er_high_pass_ops_create,
};


void factory_f2er_high_pass_init(struct factory_f2er_high_pass *factory_f2er_high_pass)
{
    factory_f2er_init(&factory_f2er_high_pass->factory_f2er);
    factory_f2er_high_pass->factory_f2er.ops = &factory_f2er_ops;
}


t_errors_f2er set_frecuencies_f2er_high_pass_init(struct factory_f2er * factory_f2er,float fc,float fs, float Q)
{
    if (fc==0.0)
        return ERROR_FC_ZERO_F2ER;
    else if (fs==0.0)
        return ERROR_FS_ZERO_F2ER;
    else if (fs<fc)
        return ERROR_FS_MINOR_FC_F2ER;
    else
    {
        factory_f2er->config.fc=(float_t)fc;
        factory_f2er->config.fs=(float_t)fs;
        factory_f2er->config.Q=(float_t)Q;
        return NO_ERROR_F2ER;
    }
}

