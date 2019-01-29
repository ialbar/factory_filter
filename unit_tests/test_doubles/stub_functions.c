/*!
 * \addtogroup test_doubles
 * \{
 */

/*!
 * \file   stub_functions.c
 * \brief  Header file of the fake functions to make tests run.
 * \author Ivan Albarran
 */
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "stub_functions.h"


void start_stub_data (void)
{
  
}

#if 0
watchdog_cell_Config watchdog;
watchdog_cell_Config * watchdog_dev;
u32 data_reg[WATCHDOG_CELL_NUM_INT_DETECT_OFFSET]={0};

/*!
 * \brief start_stub_data Configuro el dispositivo, y asigno puntero al dispositivo, equivalente al LookupConfig
 */
void start_stub_data (void)
{
  watchdog.TimesIntErrorWidth=4;
  watchdog.NumIntDetectWidth=16;
  watchdog_dev= &watchdog;
  watchdog_dev->BaseAddress=(u32)(&data_reg[0]);
}
#endif

/*! \} */ // grouping
