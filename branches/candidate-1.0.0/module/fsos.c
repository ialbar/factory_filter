#include "fsos.h"
#include "stdint.h"
#include "stdlib.h"
#include "stdio.h"

static float_t fsos_ops_filtered(struct fsos *filter, float_t input)
{
    printf("filter::filtered()\n");
}
static struct fsos_ops fsos_ops =
{
    .filtered = fsos_ops_filtered
};

void fsos_init(struct fsos *filter, uint16_t order)
{
    uint16_t index_section=0;
    uint16_t n_sections;
    uint16_t order_section;
    n_sections =order/2;
    order_section=2; //sos
    //Allocate memory
    filter->wiir = (float_t **)malloc (n_sections * sizeof(float_t *));
    filter->asos = (float_t **)malloc (n_sections * sizeof(float_t *));
    filter->bsos = (float_t **)malloc (n_sections * sizeof(float_t *));
    for (index_section=0; index_section<n_sections; index_section++)
    {
       filter->wiir[index_section] = (float_t *)malloc (order_section*sizeof(float_t));
       filter->asos[index_section] = (float_t *)malloc (order_section*sizeof(float_t));
       filter->bsos[index_section] = (float_t *)malloc (order_section*sizeof(float_t));
    }
    filter->order=order;
}

float_t fsos_filtered(struct fsos *filter, float_t input)
{
    return filter->ops->filtered(filter, input);
}
