#ifndef FACTORY_F2ER_LOW_PASS_H
#define FACTORY_F2ER_LOW_PASS_H

#include "factory_f2er.h"
#include "f2er.h"


struct factory_f2er_low_pass {
    struct factory_f2er factory_f2er;
};

void factory_f2er_low_pass_init(struct factory_f2er_low_pass *);

t_errors_f2er set_frecuencies_f2er_low_pass_init(struct factory_f2er *,float fc,float fs, float Q);

#endif // FACTORY_F2ER_LOW_PASS_H
