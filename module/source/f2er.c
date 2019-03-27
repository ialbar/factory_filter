#include "../include/f2er.h"
#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"

static float_t f2er_ops_filtered(struct f2er *filter, float_t input)
{
    printf("filter::filtered()\n");
    return (float_t)(0.0);
}
static struct f2er_ops f2er_ops = {
    .filtered = f2er_ops_filtered,
};

void f2er_init(struct f2er *filter)
{
    uint16_t index_section=0;
    uint16_t index_order=0;
    uint16_t n_sections;
    uint16_t order_section;
    n_sections =1;
    order_section=2;

    filter->wiir = (float_t **)malloc (n_sections * sizeof(float_t *));
    for (index_section=0; index_section<n_sections; index_section++)
       filter->wiir[index_section] = (float_t *)malloc (order_section*sizeof(float_t));
    // Init
    for (index_section=0; index_section<n_sections; index_section++)
    {
        for (index_order=0; index_order<order_section; index_order++)
            filter->wiir[index_section][index_order]=(float_t)0.0;
    }
    filter->a=(float_t *)malloc(order_section * sizeof(float_t)); //
    filter->b=(float_t *)malloc(order_section * sizeof(float_t)); //

    filter->ops = &f2er_ops;
}

float_t f2er_filtered(struct f2er *filter, float_t input)
{
    return filter->ops->filtered(filter, input);
}
