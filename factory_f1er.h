#ifndef factory_f1er_F1ER_H
#define factory_f1er_F1ER_H
#include "f1er.h"
#include "math.h"

struct factory_f1er_ops;

struct factory_f1er_config
{
  float_t fc;
  float_t fs;
};

struct factory_f1er {
    struct factory_f1er_config config;
    struct factory_f1er_ops *ops;
};


struct factory_f1er_ops {
    struct f1er * (*create)(struct factory_f1er *);
};
void factory_f1er_init(struct factory_f1er *);

void factory_f1er_filtered(struct factory_f1er *, float_t input);

struct f1er * factory_f1er_create(struct factory_f1er *factory_f1er);


#endif // factory_f1er_F1ER_H
