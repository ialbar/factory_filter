#include "stdio.h"
#include "../include/factory_f2er_band_pass.h"
#include "../include/f2er_bandpass.h"
#include "stdint.h"
#include "stdlib.h"
#include "math.h"
#include <complex.h>
#include "float.h"

#ifdef __TMS320C28XX__
    #define uint8_t uint16_t
    #define M_PI        3.14159265358979323846  /* pi */
#endif

static struct f2er * factory_f2er_band_pass_ops_create(struct factory_f2er *factory_f2er)
{
    struct f2er_band_pass * f2;
    struct f2er * filter;
    uint8_t j,i=0;

    float complex num_w0,den_w0=0;
    float_t gain_w0=0;
    float complex r1,r2;

    float_t w0;
    float_t Tsample;

    float_t fc=(float_t)0.0f;
    float_t fs=(float_t)0.0f;
    float_t Q =(float_t)0.0f;

    f2 = malloc(sizeof(*f2));
    f2er_band_pass_init(f2);

    fc = factory_f2er->config.fc;
    fs = factory_f2er->config.fs + FLT_EPSILON ;
    Q = factory_f2er->config.Q;

    w0= 2*M_PI*fc;
    Tsample=1/fs;

    r1=-((w0/Q)/2) + csqrtf((pow((w0/Q),2) - 4*(w0*w0)))/2;
    r2=-((w0/Q)/2) - csqrtf((pow((w0/Q),2) - 4*(w0*w0)))/2;

    filter = &(f2->f2er);

    filter->a[0]  =1; // a0
    filter->a[1]  =-(cexpf(r1*Tsample)+cexpf(r2*Tsample));
    filter->a[2]  =cexpf(r1*Tsample)*cexpf(r2*Tsample);

    gain_w0=(float_t)1.0f; // ajusto a la frecuencia de paso
    num_w0=cexpf(I*w0*Tsample)-1;
    den_w0=(filter->a[0]*cexpf(I*2*w0*Tsample) + filter->a[1]*cexpf(I*w0*Tsample) + filter->a[2]);
    filter->b[0]  =0; // b0
    filter->b[1]  =gain_w0/crealf(cabsf(num_w0/den_w0)); // b1
    filter->b[2]  =-gain_w0/crealf(cabsf(num_w0/den_w0)); // b2
    return(&(f2->f2er));
}

static struct factory_f2er_ops factory_f2er_ops = {
    .create = factory_f2er_band_pass_ops_create,
};


void factory_f2er_band_pass_init(struct factory_f2er_band_pass *factory_f2er_band_pass)
{
    factory_f2er_init(&factory_f2er_band_pass->factory_f2er);
    factory_f2er_band_pass->factory_f2er.ops = &factory_f2er_ops;
}

t_errors_f2er set_frecuencies_f2er_band_pass_init(struct factory_f2er * factory_f2er,float fc,float fs, float Q)
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

