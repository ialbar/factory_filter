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

    float complex num_wn,den_wn;
    float_t gain_wn=0;
    float_t K=0;
    float complex r1,r2;

    float_t wn;
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

    wn= (float_t)(2*(float_t)M_PI*fc);
    Tsample=1/fs;

    r1=-((wn/Q)/2) + csqrtf((pow((wn/Q),2) - 4*(wn*wn)))/2;
    r2=-((wn/Q)/2) - csqrtf((pow((wn/Q),2) - 4*(wn*wn)))/2;

    filter = &(f2->f2er);

    filter->a[0]  =1; // a0
    filter->a[1]  =-(cexpf(r1*Tsample)+cexpf(r2*Tsample));
    filter->a[2]  =cexpf(r1*Tsample)*cexpf(r2*Tsample);

    filter->b[0]  =1; // b0
    filter->b[1]  =-2; // b1
    filter->b[2]  =1; // b2
    num_wn=(filter->b[0]*cexpf(I*2*wn*Tsample) + filter->b[1]*cexpf(I*wn*Tsample) + filter->b[2]);
    den_wn=(filter->a[0]*cexpf(I*2*wn*Tsample) + filter->a[1]*cexpf(I*wn*Tsample) + filter->a[2]);
    gain_wn=1/((2*zeta)*sqrtf(1-(zeta*zeta)));
    K = gain_wn / cabsf(num_wn/den_wn);
    // bo*z^2-b12*z^1+b2
    filter->b[0]  =1*K; // b0
    filter->b[1]  =-2*K; // b1
    filter->b[2]  =1*K; // b2
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
