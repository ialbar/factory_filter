#ifndef CREATE_FILTERS_H
#define CREATE_FILTERS_H

#include "f1er.h"
#include "f2er.h"
#include "factory_f1er_low_pass.h"
#include "factory_f1er_high_pass.h"
#include "factory_f2er_low_pass.h"
#include "factory_f2er_band_pass.h"
#include "factory_f2er_high_pass.h"
#include "factory_fsos.h"
#include "stdint.h"

#ifdef __TMS320C28XX__
    #define uint8_t uint16_t
#endif

struct f1er * create_f1er_low_pass (float fc, float fs);
struct f1er * create_f1er_high_pass (float fc, float fs);
struct f2er * create_f2er_low_pass (float fc, float fs, float Q);
struct f2er * create_f2er_band_pass (float fc, float fs, float Q);
struct f2er * create_f2er_high_pass (float fc, float fs, float Q);
struct fsos * create_fsos (uint8_t order, float Ksos, float *a, float *b);



#endif // CREATE_FILTERS_H
