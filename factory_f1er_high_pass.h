#ifndef FACTORY_F1ER_HIGH_PASS_H
#define FACTORY_F1ER_HIGH_PASS_H

#include "factory_f1er.h"


struct factory_f1er_high_pass {
    struct factory_f1er factory_f1er;
};

void factory_f1er_high_pass_init(struct factory_f1er_high_pass *);
t_errors_f1er set_frecuencies_f1er_high_pass_init(struct factory_f1er * ,float ,float );



#endif // FACTORY_F1ER_HIGH_PASS_H
