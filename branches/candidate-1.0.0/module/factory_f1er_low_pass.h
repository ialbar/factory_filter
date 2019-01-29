#ifndef FACTORY_F1R_LOW_PASS_H
#define FACTORY_F1R_LOW_PASS_H

#include "factory_f1er.h"
#include "stdint.h"


struct factory_f1er_low_pass {
    struct factory_f1er factory_f1er;
};

void factory_f1er_low_pass_init(struct factory_f1er_low_pass *);

t_errors_f1er set_frecuencies_f1er_low_pass_init(struct factory_f1er *,float fc,float fs);



#endif // FACTORY_F1R_LOW_PASS_H
