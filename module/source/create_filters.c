#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "../include/create_filters.h"



#define DEBUG

#ifdef DEBUG
    #define IS_IN_DEBUG 1
#else
    #define IS_IN_DEBUG 0
#endif

struct f1er * create_f1er_low_pass (float fc, float fs)
{
    t_errors_f1er error=NO_ERROR;
    struct factory_f1er_low_pass * factory;
    factory = malloc(sizeof(*factory));
    factory_f1er_low_pass_init(factory);
    error=set_frecuencies_f1er_low_pass_init(&factory->factory_f1er,fc,fs);
    switch (error) {
    case ERROR_FC_ZERO:
        if (IS_IN_DEBUG)
            printf ("create_f1er_low_pass:ERROR_FC_ZERO\n");
        return NULL;
        break;
    case ERROR_FS_ZERO:
        if (IS_IN_DEBUG)
            printf ("create_f1er_low_pass:ERROR_FS_ZERO\n");
        return NULL;
        break;
    case ERROR_FS_MINOR_FC:
        if (IS_IN_DEBUG)
           printf ("create_f1er_low_pass:ERROR_FS_MINOR_FC\n");
        return NULL;
        break;
    case NO_ERROR:
        if (IS_IN_DEBUG)
           printf ("create_f1er_low_pass: NO_ERROR\n");
        return factory_f1er_create(&factory->factory_f1er);
        break;
    default:
        return NULL;
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
            printf ("create_f1er_high_pass:ERROR_FC_ZERO\n");
        return NULL;
        break;
    case ERROR_FS_ZERO:
        if (IS_IN_DEBUG)
            printf ("create_f1er_high_pass:ERROR_FS_ZERO\n");
        return NULL;
        break;
    case ERROR_FS_MINOR_FC:
        if (IS_IN_DEBUG)
            printf ("create_f1er_high_pass:ERROR_FS_MINOR_FC\n");
        return NULL;
        break;
    case NO_ERROR:
        if (IS_IN_DEBUG)
            printf ("create_f1er_high_pass: NO_ERROR\n");
        return (factory_f1er_create(&factory->factory_f1er));
        break;
    default:
        return NULL;
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
            printf ("create_f2er_low_pass:ERROR_FC_ZERO_F2ER\n");
        return NULL;
        break;
    case ERROR_FS_ZERO_F2ER:
        if (IS_IN_DEBUG)
            printf ("create_f2er_low_pass:ERROR_FS_ZERO_F2ER\n");
        return NULL;
        break;
    case ERROR_FS_MINOR_FC_F2ER:
        if (IS_IN_DEBUG)
            printf ("create_f2er_low_pass:ERROR_FS_MINOR_FC_F2ER\n");
        return NULL;
        break;
    case NO_ERROR_F2ER:
        if (IS_IN_DEBUG)
            printf ("create_f2er_low_pass: NO_ERROR\n");
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
            printf ("create_f2er_high_pass:ERROR_FC_ZERO_F2ER\n");
        return NULL;
        break;
    case ERROR_FS_ZERO_F2ER:
        if (IS_IN_DEBUG)
            printf ("create_f2er_high_pass:ERROR_FS_ZERO_F2ER\n");
        return NULL;
        break;
    case ERROR_FS_MINOR_FC_F2ER:
        if (IS_IN_DEBUG)
            printf ("create_f2er_high_pass:ERROR_FS_MINOR_FC_F2ER\n");
        return NULL;
        break;
    case NO_ERROR_F2ER:
        if (IS_IN_DEBUG)
            printf ("create_f2er_high_pass: NO_ERROR\n");
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
            printf ("create_f2er_band_pass:ERROR_FC_ZERO_F2ER\n");
        return NULL;
        break;
    case ERROR_FS_ZERO_F2ER:
        if (IS_IN_DEBUG)
            printf ("create_f2er_band_pass:ERROR_FS_ZERO_F2ER\n");
        return NULL;
        break;
    case ERROR_FS_MINOR_FC_F2ER:
        if (IS_IN_DEBUG)
            printf ("create_f2er_band_pass:ERROR_FS_MINOR_FC_F2ER\n");
        return NULL;
        break;
    case NO_ERROR_F2ER:
        if (IS_IN_DEBUG)
            printf ("create_f2er_band_pass: NO_ERROR\n");
        return (factory_f2er_create(&factory->factory_f2er));
        break;
    default:
        break;
    }
}

struct fsos * create_fsos (uint8_t order, float Ksos, float *a, float *b)
{
    struct factory_fsos * factory;
    if (order<2)
    {
        if (IS_IN_DEBUG)
            printf ("create_fsos: ORDER_FALL\n");
        return NULL;
    }
    if (a==NULL)
    {
        printf ("create_fsos: A_COEF_VECTOR_IS_NULL\n");
        return NULL;
    }
    if (b==NULL)
    {
        printf ("create_fsos: B_COEF_VECTOR_IS_NULL\n");
        return NULL;
    }
    factory = malloc(sizeof(*factory));
    factory_fsos_init(factory);
    factory->config.order=order;
    factory->config.Ksos=(float_t)(Ksos);
    factory->config.asos=a;
    factory->config.bsos=b;
    if (IS_IN_DEBUG)
        printf ("create_fsos: NO_ERROR\n");
    return (factory_fsos_create(factory));
}



