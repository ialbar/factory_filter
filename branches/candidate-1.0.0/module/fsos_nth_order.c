#include "fsos_nth_order.h"
#include "stdint.h"

static float_t fsos_nth_order_ops_filtered(struct fsos *fsos, float_t input)
{
    uint16_t i,j=0;
    float_t temp=0;
    //if a0=1 the output y could be expressed by
    // y(n)=[bo*x(n)+b1*x(n-1)+.....]-[a1*y(n-1)+a2*y(n-2)]
    temp = input;
    for (j=0;j<fsos->order/2;j++)
    {
        fsos->wiir[j][0]=fsos->wiir[j][1];

        fsos->wiir[j][0]= temp  - (
                    (fsos->asos[j][1]) * (fsos->wiir[j][1])+
                    (fsos->asos[j][2]) * (fsos->wiir[j][2])
                    );

        temp =  (fsos->bsos[j][0])   * (fsos->wiir[j][0]) +
                (fsos->bsos[j][1]) * (fsos->wiir[j][1]) +
                (fsos->bsos[j][2]) * (fsos->wiir[j][2]) ;

    }
    for (j=0;j<fsos->order/2;j++)
    {
        for (i=2;i>0;i--) // Second Order Section
            fsos->wiir[j][i]=fsos->wiir[j][i-1];
    }
    return temp*fsos->Ksos;
}

static struct fsos_ops fsos_ops = {
    .filtered = fsos_nth_order_ops_filtered,
};


void fsos_nth_order_init(struct fsos_nth_order *fsos_nth_order, uint16_t order)
{
    fsos_init(&fsos_nth_order->fsos, order);
    fsos_nth_order->fsos.ops=&fsos_ops;
}

