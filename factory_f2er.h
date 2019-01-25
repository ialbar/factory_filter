#ifndef FACTORY_F2ER_H
#define FACTORY_F2ER_H
#include "math.h"

struct factory_f2er_ops;

struct factory_f2er_config
{
  float_t fc;
  float_t fs;
  float_t Q;
};

struct factory_f2er {
    struct factory_f2er_config config;
    struct factory_f2er_ops *ops;
};


struct factory_f2er_ops {
    struct f2er * (*create)(struct factory_f2er *);
};
void factory_f2er_init(struct factory_f2er *);

void factory_f2er_filtered(struct factory_f2er *, float_t input);

struct f2er * factory_f2er_create(struct factory_f2er *factory_f2er);

#endif // FACTORY_F2ER_H
