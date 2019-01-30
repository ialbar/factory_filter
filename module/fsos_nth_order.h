#ifndef FSOS_NTH_ORDER_H
#define FSOS_NTH_ORDER_H
#include "fsos.h"

struct fsos_nth_order {
    struct fsos fsos;
};

void fsos_nth_order_init(struct fsos_nth_order *, uint16_t order);




#endif // FSOS_NTH_ORDER_H
