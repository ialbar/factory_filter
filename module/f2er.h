#ifndef F2ER_H
#define F2ER_H
#include "math.h"

typedef enum errors_f2er {
    NO_ERROR_F2ER=0,
    ERROR_FS_ZERO_F2ER = -1,
    ERROR_FC_ZERO_F2ER = -2,
    ERROR_FS_MINOR_FC_F2ER = -3,
}t_errors_f2er;

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
