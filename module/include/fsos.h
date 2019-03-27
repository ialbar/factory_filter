#ifndef FSOS_H
#define FSOS_H
#include "stdint.h"
#include "math.h"

#ifdef __TMS320C28XX__
    #define float_t float
#endif

struct fsos_ops;
struct fsos
{
    struct fsos_ops *ops;
    // Second Order Stages
    float_t Ksos;
    float_t ** bsos;
    float_t ** asos;
    float_t ** wiir;
    uint16_t order;
};

struct fsos_ops {
    float_t (*filtered)(struct fsos *, float_t input);
};
void fsos_init(struct fsos *, uint16_t order);


float_t fsos_filtered(struct fsos *fsos, float_t input);

#endif // FSOS_H
