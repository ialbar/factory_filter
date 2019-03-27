#include "../include/f1er.h"
#include "stdio.h"
#include "stdint.h"
#include "math.h"
#include <stdlib.h>
#include <string.h>


static float_t f1er_ops_filtered(struct f1er *filter, float_t input)
{
    printf("filter::filtered()\n");
    return (float_t)0.0;
}

static struct f1er_ops f1er_ops = {
    .filtered = f1er_ops_filtered,
};

void f1er_init(struct f1er *filter)
{
    filter->a=(float_t *)malloc(2 * sizeof(float_t));
    filter->b=(float_t *)malloc(2 * sizeof(float_t));
    filter->yiir=(float_t *)malloc(2 * sizeof(float_t));
    filter->xiir=(float_t *)malloc(2 * sizeof(float_t));
    filter->ops = &f1er_ops;
}

float_t f1er_filtered(struct f1er *filter, float_t input)
{
    return filter->ops->filtered(filter, input);
}

