#include "factory_f2er.h"

static struct f2er * factory_f2er_ops_create(struct factory_f2er *factory_f2er)
{
    return 0;
}
static struct factory_f2er_ops factory_f2er_ops = {
    .create = factory_f2er_ops_create,
};

void factory_f2er_init(struct factory_f2er *factory_f2er)
{
    memset(factory_f2er, sizeof(*factory_f2er), 0);
    factory_f2er->ops = &factory_f2er_ops;
}


void factory_f2er_filtered(struct factory_f2er *factory_f2er, float_t input)
{
}


struct f2er * factory_f2er_create(struct factory_f2er *factory_f2er)
{
    return factory_f2er->ops->create(factory_f2er);
}
