#include "stdio.h"
#include "factory_f2er_low_pass.h"
#include "f2er_lowpass.h"
#include "stdint.h"
#include "stdlib.h"
#include "math.h"
#include "float.h"
#include <complex.h>

static struct f2er * factory_f2er_low_pass_ops_create(struct factory_f2er *factory_f2er)
{

    struct f2er_low_pass * f2;
    struct f2er * filter;

    float complex r1,r2;
    float_t wn;
    float_t Tsample;

    float_t fc;
    float_t fs;
    float_t Q;


    f2 = malloc(sizeof(*f2));
    f2er_low_pass_init(f2);

    fc = factory_f2er->config.fc;
    fs = factory_f2er->config.fs + (float_t)FLT_EPSILON;
    Q = factory_f2er->config.Q;

    wn= 2*(float_t)M_PI*fc;
    Tsample=1/fs;

    r1=-((wn/Q)/2) + csqrtf((pow((wn/Q),2) - 4*(wn*wn)))/2;
    r2=-((wn/Q)/2) - csqrtf((pow((wn/Q),2) - 4*(wn*wn)))/2;

    filter = &(f2->f2er);

    filter->a[0]  =1; // a0
    filter->a[1]  =-(cexpf(r1*Tsample)+cexpf(r2*Tsample));
    filter->a[2]  =cexpf(r1*Tsample)*cexpf(r2*Tsample);
    filter->b[0]  =0; // b0
    filter->b[1]  =0; // b1
    filter->b[2]  =filter->a[0]+filter->a[1]+filter->a[2]; // b2
    return(&(f2->f2er));

}

static struct factory_f2er_ops factory_f2er_ops = {
    .create = factory_f2er_low_pass_ops_create,
};


void factory_f2er_low_pass_init(struct factory_f2er_low_pass *factory_f2er_low_pass)
{
    factory_f2er_init(&factory_f2er_low_pass->factory_f2er);
    factory_f2er_low_pass->factory_f2er.ops = &factory_f2er_ops;
}

