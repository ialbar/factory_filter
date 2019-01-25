#ifndef F2ER_H
#define F2ER_H
#include "math.h"

struct f2er_ops;
struct f2er
{
    struct f2er_ops *ops;
    // coefficients in first/second order
    float_t* b;
    float_t* a;
    // Direct Form II in Second Order and Sos
    float_t** wiir;
};

struct f2er_ops {
    float_t (*filtered)(struct f2er *, float_t input);
};
void f2er_init(struct f2er *);


float_t f2er_filtered(struct f2er *f2er, float_t input);

#endif // F2ER_H
