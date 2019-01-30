#ifndef FACTORY_FSOS_H
#define FACTORY_FSOS_H
#include "fsos.h"
#include "stdint.h"
#include "math.h"


struct factory_fsos_ops;

struct factory_fsos_config
{
  float_t * bsos;
  float_t * asos;
  float_t Ksos;
  uint16_t order;
};

struct factory_fsos {
    struct factory_fsos_config config;
    struct factory_fsos_ops *ops;
};


struct factory_fsos_ops {
    struct fsos * (*create)(struct factory_fsos *);
};
void factory_fsos_init(struct factory_fsos *);

void factory_fsos_filtered(struct factory_fsos *, float_t input);

struct fsos * factory_fsos_create(struct factory_fsos *factory_fsos);


#endif // FACTORY_FSOS_H
