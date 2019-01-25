#include <stdio.h>
#include <stdlib.h>
#include "f1er.h"
#include "f2er.h"
#include "factory_f1er_low_pass.h"
#include "factory_f1er_high_pass.h"
#include "factory_f2er_low_pass.h"
#include "factory_f2er_band_pass.h"
#include "factory_f2er_high_pass.h"
#include "factory_fsos.h"
#include "stdint.h"
#include "math.h"

#define N 20

int main()
{
    uint8_t i=0;
    struct f1er * filtro1;
    struct f1er * filtro2;
    struct f2er * filtro3;
    struct f2er * filtro4;
    struct f2er * filtro5;
    struct fsos * filtro6;

    struct factory_f1er_low_pass * factory1;
    struct factory_f1er_high_pass * factory2;
    struct factory_f2er_low_pass * factory3;
    struct factory_f2er_band_pass * factory4;
    struct factory_f2er_high_pass * factory5;
    struct factory_fsos * factory6;

    uint8_t error=NO_ERROR;

    float_t bsos[6]={1.0,2.0,1.0,1.0,2.0,1.0}; // Sos1, Sos2
    float_t asos[6]={1.0,-0.8659,0.21,1.0,-1.1249,0.5777}; //Sos1, Sos2

    float_t udc[N], udc2[N];
    float_t udc_second[N],udc_second_band_pass[N],udc_second_high_pass[N];
    float_t udc_fsos[N];

    factory1 = malloc(sizeof(*factory1));
    factory_f1er_low_pass_init(factory1);
//    factory1->factory_f1er.config.fc=(float_t)1.0;
//    factory1->factory_f1er.config.fs=(float_t)0.0;
    error=set_frecuencies_f1er_low_pass_init(&factory1->factory_f1er,0.0,1.0);
    filtro1=factory_f1er_create(&factory1->factory_f1er);

    factory2 = malloc(sizeof(*factory2));
    factory_f1er_high_pass_init(factory2);
    factory2->factory_f1er.config.fc=(float_t)0.1e3;
    factory2->factory_f1er.config.fs=(float_t)10.0e3;
    filtro2=factory_f1er_create(&factory2->factory_f1er);

    factory3 = malloc(sizeof(*factory3));
    factory_f2er_low_pass_init(factory3);
    factory3->factory_f2er.config.fc=(float_t)1.0;
    factory3->factory_f2er.config.fs=(float_t)0.0;
    factory3->factory_f2er.config.Q=(float_t)0.6;
    filtro3=factory_f2er_create(&factory3->factory_f2er);

    factory4 = malloc(sizeof(*factory4));
    factory_f2er_band_pass_init(factory4);
    factory4->factory_f2er.config.fc=(float_t)1.0;
    factory4->factory_f2er.config.fs=(float_t)0.0;
    factory4->factory_f2er.config.Q=(float_t)0.6;
    filtro4=factory_f2er_create(&factory4->factory_f2er);

    factory5 = malloc(sizeof(*factory5));
    factory_f2er_high_pass_init(factory5);
    factory5->factory_f2er.config.fc=1;
    factory5->factory_f2er.config.fs=0;
    factory5->factory_f2er.config.Q=(float_t)1.0;
    filtro5=factory_f2er_create(&factory5->factory_f2er);

    factory6 = malloc(sizeof(*factory6));
    factory_fsos_init(factory6);
    factory6->config.order=4;
    factory6->config.Ksos=(float_t)(0.0098);
    factory6->config.asos=&asos[0];
    factory6->config.bsos=&bsos[0];
    filtro6=factory_fsos_create(factory6);

    for (i=0;i<N;i++)
    {
        udc[i]=f1er_filtered(filtro1,1.0);
        udc2[i]=f1er_filtered(filtro2,1.0);
        udc_second[i]=f2er_filtered(filtro3,1.0);
        udc_second_band_pass[i]=f2er_filtered(filtro4,1.0);
        udc_second_high_pass[i]=f2er_filtered(filtro5,1.0);
        udc_fsos[i]=fsos_filtered(filtro6,1.0);
        printf("fp1:%f\t",(float)udc[i]);
        printf("fp2:%f\t",(float)udc2[i]);
        printf("fpbajo2th:%f\t",(float)udc_second[i]);
        printf("fpbanda2th:%f\t",(float)udc_second_band_pass[i]);
        printf("fpalto2th:%f\t",(float)udc_second_high_pass[i]);
        printf("fsosth:%f\n",(float)udc_fsos[i]);
    }
    return 0;
}
