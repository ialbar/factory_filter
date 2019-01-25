#include "factory_fsos.h"
#include "fsos_nth_order.h"
#include "math.h"
#include <complex.h>
#include "string.h"
#include "stdlib.h"

static struct fsos * factory_fsos_ops_create(struct factory_fsos *factory_fsos)
{
    uint16_t index_section=0;
    uint16_t index_order=0;
    uint16_t n_sections;
    uint16_t order_section;
    n_sections =factory_fsos->config.order/2;
    order_section=2; //sos
    struct fsos_nth_order * fsos_nth;
    struct fsos * filter;

    fsos_nth = malloc(sizeof(struct fsos_nth *));
    fsos_nth_order_init(fsos_nth,factory_fsos->config.order);
    filter = &(fsos_nth->fsos);

    // Init
    for (index_section=0; index_section<n_sections; index_section++)
    {
        for (index_order=0; index_order<order_section+1; index_order++)
        {
            filter->wiir[index_section][index_order]=(float_t)0.0;
            filter->asos[index_section][index_order]=factory_fsos->config.asos[index_section*3+index_order];
            filter->bsos[index_section][index_order]=factory_fsos->config.bsos[index_section*3+index_order];
        }
    }
    filter->Ksos=factory_fsos->config.Ksos;
    return (&fsos_nth->fsos);


}
static struct factory_fsos_ops factory_fsos_ops = {
    .create = factory_fsos_ops_create,
};

void factory_fsos_init(struct factory_fsos *factory_fsos)
{
    factory_fsos->ops = &factory_fsos_ops;
}


void factory_fsos_filtered(struct factory_fsos *factory_fsos, float_t input)
{
}


struct fsos * factory_fsos_create(struct factory_fsos *factory_fsos)
{
    return factory_fsos->ops->create(factory_fsos);
}
