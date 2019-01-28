#include <stdio.h>
#include <stdlib.h>
#include "create_filters.h"
#ifdef DEBUG
    #define IS_IN_DEBUG 1
#else
    #define IS_IN_DEBUG 0
#endif

struct f1er *  create_f1er_low_pass (float fc, float fs)
{
    t_errors_f1er error=NO_ERROR;
    struct factory_f1er_low_pass * factory;
    factory = malloc(sizeof(*factory));
    factory_f1er_low_pass_init(factory);
    error=set_frecuencies_f1er_low_pass_init(&factory->factory_f1er,fc,fs);
    switch (error) {
    case ERROR_FC_ZERO:
        if (IS_IN_DEBUG)
            printf ("la frecuencia de corte es 0\n");
        return ERROR_FC_ZERO;
        break;
    case ERROR_FS_ZERO:
        if (IS_IN_DEBUG)
            printf ("la frecuencia de muestreo es 0\n");
        return ERROR_FS_ZERO;
        break;
    case ERROR_FS_MINOR_FC:
        if (IS_IN_DEBUG)
           printf ("la frecuencia de muestreo es menor que la frecuencia de cortte\n");
        return ERROR_FS_MINOR_FC;
        break;
    case NO_ERROR:
        return (factory_f1er_create(&factory->factory_f1er));
        break;
    default:
        return 0;
        break;
    }
}


struct f1er *  create_f1er_high_pass (float fc, float fs)
{
    t_errors_f1er error=NO_ERROR;
    struct factory_f1er_high_pass * factory;
    factory = malloc(sizeof(*factory));
    factory_f1er_high_pass_init(factory);
    error=set_frecuencies_f1er_high_pass_init(&factory->factory_f1er,fc,fs);
    switch (error) {
    case ERROR_FC_ZERO:
        if (IS_IN_DEBUG)
            printf ("la frecuencia de corte es 0\n");
        return 0;
        break;
    case ERROR_FS_ZERO:
        if (IS_IN_DEBUG)
            printf ("la frecuencia de muestreo es 0\n");
        return 0;
        break;
    case ERROR_FS_MINOR_FC:
        if (IS_IN_DEBUG)
            printf ("la frecuencia de muestreo es menor que la frecuencia de cortte\n");
        return 0;
        break;
    case NO_ERROR:
        return (factory_f1er_create(&factory->factory_f1er));
        break;
    default:
        return 0;
        break;
    }

}

struct f2er * create_f2er_low_pass (float fc, float fs, float Q)
{
    t_errors_f2er error=NO_ERROR_F2ER;
    struct factory_f2er_low_pass * factory;
    factory = malloc(sizeof(*factory));
    factory_f2er_low_pass_init(factory);
    error=set_frecuencies_f2er_low_pass_init(&factory->factory_f2er,fc,fs,Q);
    switch (error) {
    case ERROR_FC_ZERO_F2ER:
        if (IS_IN_DEBUG)
            printf ("la frecuencia de corte es 0\n");
        return 0;
        break;
    case ERROR_FS_ZERO_F2ER:
        if (IS_IN_DEBUG)
            printf ("la frecuencia de muestreo es 0\n");
        return 0;
        break;
    case ERROR_FS_MINOR_FC_F2ER:
        if (IS_IN_DEBUG)
            printf ("la frecuencia de muestreo es menor que la frecuencia de cortte\n");
        return 0;
        break;
    case NO_ERROR_F2ER:
        return (factory_f2er_create(&factory->factory_f2er));
        break;
    default:
        break;
    }
}

struct f2er * create_f2er_high_pass (float fc, float fs, float Q)
{
    t_errors_f2er error=NO_ERROR_F2ER;
    struct factory_f2er_high_pass * factory;
    factory = malloc(sizeof(*factory));
    factory_f2er_high_pass_init(factory);
    error=set_frecuencies_f2er_high_pass_init(&factory->factory_f2er,fc,fs,Q);
    switch (error) {
    case ERROR_FC_ZERO_F2ER:
        if (IS_IN_DEBUG)
            printf ("la frecuencia de corte es 0\n");
        return 0;
        break;
    case ERROR_FS_ZERO_F2ER:
        if (IS_IN_DEBUG)
            printf ("la frecuencia de muestreo es 0\n");
        return 0;
        break;
    case ERROR_FS_MINOR_FC_F2ER:
        if (IS_IN_DEBUG)
            printf ("la frecuencia de muestreo es menor que la frecuencia de cortte\n");
        return 0;
        break;
    case NO_ERROR_F2ER:
        return (factory_f2er_create(&factory->factory_f2er));
        break;
    default:
        break;
    }
}



struct f2er * create_f2er_band_pass (float fc, float fs, float Q)
{
    t_errors_f2er error=NO_ERROR_F2ER;
    struct factory_f2er_band_pass * factory;
    factory = malloc(sizeof(*factory));
    factory_f2er_band_pass_init(factory);
    error=set_frecuencies_f2er_band_pass_init(&factory->factory_f2er,fc,fs,Q);
    switch (error) {
    case ERROR_FC_ZERO_F2ER:
        if (IS_IN_DEBUG)
            printf ("la frecuencia de corte es 0\n");
        return 0;
        break;
    case ERROR_FS_ZERO_F2ER:
        if (IS_IN_DEBUG)
            printf ("la frecuencia de muestreo es 0\n");
        return 0;
        break;
    case ERROR_FS_MINOR_FC_F2ER:
        if (IS_IN_DEBUG)
            printf ("la frecuencia de muestreo es menor que la frecuencia de cortte\n");
        break;
    case NO_ERROR_F2ER:
        return (factory_f2er_create(&factory->factory_f2er));
        break;
    default:
        break;
    }
}

struct fsos * create_fsos (uint8_t order, float Ksos, float *a, float *b)
{
    struct factory_fsos * factory;
    factory = malloc(sizeof(*factory));
    factory_fsos_init(factory);
    factory->config.order=order;
    factory->config.Ksos=(float_t)(Ksos);
    factory->config.asos=a;
    factory->config.bsos=b;
    return (factory_fsos_create(factory));
}



