#include "stdio.h"
#include "factory_f2er_band_pass.h"
#include "f2er_bandpass.h"
#include "stdint.h"
#include "stdlib.h"
#include "math.h"
#include <complex.h>
#include "float.h"

static struct f2er * factory_f2er_band_pass_ops_create(struct factory_f2er *factory_f2er)
{
    struct f2er_band_pass * f2;
    struct f2er * filter;
    uint8_t j,i=0;

    float complex num_wn,den_wn=0;
    float_t gain_wn=0;
    float complex r1,r2;

    float_t wn;
    float_t Tsample;

    float_t fc=(float_t)0.0f;
    float_t fs=(float_t)0.0f;
    float_t Q =(float_t)0.0f;

    f2 = malloc(sizeof(*f2));
    f2er_band_pass_init(f2);

    fc = factory_f2er->config.fc;
    fs = factory_f2er->config.fs + FLT_EPSILON ;
    Q = factory_f2er->config.Q;

    wn= 2*M_PI*fc;
    Tsample=1/fs;

    r1=-((wn/Q)/2) + csqrtf((pow((wn/Q),2) - 4*(wn*wn)))/2;
    r2=-((wn/Q)/2) - csqrtf((pow((wn/Q),2) - 4*(wn*wn)))/2;

    filter = &(f2->f2er);

    filter->a[0]  =1; // a0
    filter->a[1]  =-(cexpf(r1*Tsample)+cexpf(r2*Tsample));
    filter->a[2]  =cexpf(r1*Tsample)*cexpf(r2*Tsample);

    gain_wn=(float_t)1.0f; // ajusto a la frecuencia de paso
    num_wn=cexpf(I*wn*Tsample)-1;
    den_wn=(filter->a[0]*cexpf(I*2*wn*Tsample) + filter->a[1]*cexpf(I*wn*Tsample) + filter->a[2]);
    filter->b[0]  =0; // b0
    filter->b[1]  =gain_wn/crealf(cabsf(num_wn/den_wn)); // b1
    filter->b[2]  =-gain_wn/crealf(cabsf(num_wn/den_wn)); // b2
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

