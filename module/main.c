#include <stdio.h>
#include <stdlib.h>
#include "stdint.h"
#include "math.h"
#include "f1er.h"
#include "f2er.h"
#include "fsos.h"
#include "create_filters.h"

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


    float_t bsos[6]={1.0,2.0,1.0,1.0,2.0,1.0}; // Sos1, Sos2
    float_t asos[6]={1.0,-0.8659,0.21,1.0,-1.1249,0.5777}; //Sos1, Sos2

    float_t udc[N], udc2[N];
    float_t udc_second[N],udc_second_band_pass[N],udc_second_high_pass[N];
    float_t udc_fsos[N];

    if (!(filtro1=create_f1er_low_pass(1.0,10.0)))
        return -1;
    if (!(filtro2=create_f1er_high_pass(0.1,10.0)))
        return -1;
    if (!(filtro3=create_f2er_low_pass(100.0,10.0e3,4.0)))
       return -1;
    if (!(filtro4=create_f2er_band_pass(1.0e3,10.0e3,12)))
        return -1;
    if (!(filtro5=create_f2er_high_pass(2.0e3,10.0e3,20)))
        return -1;
    if (!(filtro6=create_fsos (4, 0.0098,&asos[0], &bsos[0])))
        return -1;

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


