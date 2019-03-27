#include "../include/factory_f1er.h"

static struct f1er * factory_f1er_ops_create(struct factory_f1er *factory_f1er)
{
    printf("factory_f1er::create()\n");
    return 0;
}
static struct factory_f1er_ops factory_f1er_ops = {
    .create = factory_f1er_ops_create,
};

void factory_f1er_init(struct factory_f1er *factory_f1er)
{
    memset(factory_f1er, sizeof(*factory_f1er), 0);
    factory_f1er->ops = &factory_f1er_ops;
}


void factory_f1er_filtered(struct factory_f1er *factory_f1er, float_t input)
{
    printf("factory_f1er::do_it()\n");
}


struct f1er * factory_f1er_create(struct factory_f1er *factory_f1er)
{
    return factory_f1er->ops->create(factory_f1er);
}
