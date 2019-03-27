#ifndef F1ER_H
#define F1ER_H
#include "math.h"

#ifdef __TMS320C28XX__
    #define float_t float
#endif

typedef enum errors_f1er {
    NO_ERROR=0,
    ERROR_FS_ZERO = -1,
    ERROR_FC_ZERO = -2,
    ERROR_FS_MINOR_FC = -3,
}t_errors_f1er;

struct f1er_ops;
struct f1er
{
    struct f1er_ops *ops;
    // coefficients in first/second order
    float_t* b;
    float_t* a;
    // Direct Form I in First Order
    float_t* yiir;
    float_t* xiir;
};

struct f1er_ops {
    float_t (*filtered)(struct f1er *, float_t input);
};
void f1er_init(struct f1er *);


float_t f1er_filtered(struct f1er *f1er, float_t input);


#endif // F1ER_H
