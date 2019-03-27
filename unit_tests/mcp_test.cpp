/*!
 * \addtogroup test
 * \{
 */

/*!
 * \file   mcp_test.cpp
 * \brief  Test file for WatchDog Cell API
 * \author Ivan Albarran
 */

#include <CppUTest/TestHarness.h>
#include <iostream>
#include "stdint.h"

using namespace std;

extern "C"
{
	#include "test_doubles/stub_functions.h"
  #include "../module/include/create_filters.h"
}

/*!
 * \brief Grupo de tests que se encargan de test la inicialización del módulo
 */
TEST_GROUP( InitTestGroup )
{
  void setup ()
  {
    start_stub_data();
  }
};


#if 0
/*!
 * \brief  Test que testea el acceso al módulo
 */
TEST( InitTestGroup, CheckAccessToTheModule)
{
  CHECK_EQUAL(XST_SUCCESS, watchdog_cell_selftest(0));
}
#endif


/*!
 * \brief Grupo de test pone bajo prueba los setters y getters
 */
TEST_GROUP( CheckTestGroup )
{
  void setup ()
  {
    start_stub_data();
  }
};

/*!
 * \brief  Checking F1er Low pass Filter
 */
TEST( CheckTestGroup, Checkf1erCreateFilter)
{
  float fc;
  float fs=10.0;
  struct f1er *  filtro;
  
  fc=0.0;
  filtro= create_f1er_low_pass (fc, fs);
  CHECK_EQUAL(NULL, filtro);

  fs=0.0;
  fc=10.0;
  filtro= create_f1er_low_pass (fc, fs);
  CHECK_EQUAL(NULL, filtro);

  fc=10.0;
  fs=1.0;  
  filtro= create_f1er_low_pass (fc, fs);
  CHECK_EQUAL(NULL, filtro);


  fc=0.0;
  filtro= create_f1er_high_pass (fc, fs);
  CHECK_EQUAL(NULL, filtro);

  fs=0.0;
  fc=10.0;
  filtro= create_f1er_high_pass (fc, fs);
  CHECK_EQUAL(NULL, filtro);

  fc=10.0;
  fs=1.0;  
  filtro= create_f1er_high_pass (fc, fs);
  CHECK_EQUAL(NULL, filtro);  
}

/*!
 * \brief  Checking F1er Low pass Filter
 */
TEST( CheckTestGroup, Checkf2erCreateFilter)
{
  float fc;
  float fs=10.0;
  float Q=10.0;
  struct f2er *  filtro;
  
  fc=0.0;
  filtro= create_f2er_low_pass (fc, fs,Q);
  CHECK_EQUAL(NULL, filtro);

  fs=0.0;
  fc=10.0;
  filtro= create_f2er_low_pass (fc, fs,Q);
  CHECK_EQUAL(NULL, filtro);

  fc=10.0;
  fs=1.0;  
  filtro= create_f2er_low_pass (fc, fs,Q);
  CHECK_EQUAL(NULL, filtro);


  fc=0.0;
  filtro= create_f2er_high_pass (fc, fs,Q);
  CHECK_EQUAL(NULL, filtro);

  fs=0.0;
  fc=10.0;
  filtro= create_f2er_high_pass (fc, fs,Q);
  CHECK_EQUAL(NULL, filtro);

  fc=10.0;
  fs=1.0;  
  filtro= create_f2er_high_pass (fc, fs,Q);
  CHECK_EQUAL(NULL, filtro);  

  fc=0.0;
  filtro= create_f2er_band_pass (fc, fs,Q);
  CHECK_EQUAL(NULL, filtro);

  fs=0.0;
  fc=10.0;
  filtro= create_f2er_band_pass (fc, fs,Q);
  CHECK_EQUAL(NULL, filtro);

  fc=10.0;
  fs=1.0;  
  filtro= create_f2er_band_pass (fc, fs,Q);
  CHECK_EQUAL(NULL, filtro); 

}

/*!
 * \brief  Checking Fsos Create Filter
 */
TEST( CheckTestGroup, CheckfsosCreateFilter)
{
  float a[4]={0.0};
  float b[4]={0.0};
  float Ksos = 0.0;
  uint8_t order = 0;
  struct fsos *  filtro;
  order= 0;
  filtro= create_fsos (order,Ksos,a,b);
  CHECK_EQUAL(NULL, filtro);

  order= 4;
  filtro= create_fsos (order,Ksos,NULL,b);
  CHECK_EQUAL(NULL, filtro);

  order= 4;
  filtro= create_fsos (order,Ksos,a,NULL);
  CHECK_EQUAL(NULL, filtro);

  order= 4;
  filtro= create_fsos (order,Ksos,a,b);
  CHECK(filtro);
}
#if 0
/*!
 * \brief  Checking Start function
 */
TEST( CheckTestGroup, CheckStartFunction)
{
  CHECK_EQUAL(XST_SUCCESS, watchdog_cell_set_start(watchdog_dev));
  u32 data_test= data_reg[WATCHDOG_CELL_CTRL_REG_OFFSET];
  data_test&=WATCHDOG_CELL_CTRL_REG_START_MASK;
  data_test=data_test>>WATCHDOG_CELL_CTRL_REG_START_BIT;
  CHECK_EQUAL(TRUE, data_test);
}

/*!
 * \brief  Checking Stop function
 */
TEST( CheckTestGroup, CheckStopFunction)
{
  data_reg[WATCHDOG_CELL_CTRL_REG_OFFSET]|=WATCHDOG_CELL_CTRL_REG_START_MASK; /*! Primero escribo como si ya estuviera andando el módulo */
  CHECK_EQUAL(XST_SUCCESS, watchdog_cell_set_stop(watchdog_dev));
  u32 data_test= data_reg[WATCHDOG_CELL_CTRL_REG_OFFSET];
  data_test&=WATCHDOG_CELL_CTRL_REG_START_MASK;
  data_test=data_test>>WATCHDOG_CELL_CTRL_REG_START_BIT;
  CHECK_EQUAL(FALSE, data_test);
}

/*!
 * \brief  Checking Interrupt Enable function
 */
TEST( CheckTestGroup, CheckInterruptEnable)
{
  CHECK_EQUAL(XST_SUCCESS, watchdog_cell_interrupt_enable(watchdog_dev));
  u32 data_test= data_reg[WATCHDOG_CELL_CTRL_REG_OFFSET]; /*! Test CTRL_REG */
  data_test&=WATCHDOG_CELL_CTRL_REG_IE_MASK;
  data_test=data_test>>WATCHDOG_CELL_CTRL_REG_IE_BIT;
  CHECK_EQUAL(TRUE, data_test);
  data_test= data_reg[WATCHDOG_CELL_IE_REG_OFFSET]; /*! Test IE_REG */
  data_test&=WATCHDOG_CELL_INTR_MASK;
  data_test=data_test>>WATCHDOG_CELL_INTR_BIT;
  CHECK_EQUAL(TRUE, data_test);
}
/*!
 * \brief  Checking Interrupt ACK function
 */
TEST( CheckTestGroup, CheckInterruptAck)
{
  CHECK_EQUAL(XST_SUCCESS, watchdog_cell_interrupt_acknowledge(watchdog_dev));
  u32 data_test= data_reg[WATCHDOG_CELL_IF_REG_OFFSET]; /*! Test IF_REG */
  data_test&=WATCHDOG_CELL_INTR_MASK;
  data_test=data_test>>WATCHDOG_CELL_INTR_BIT;
  CHECK_EQUAL(TRUE, data_test);
}


/*!
 * \brief  Setting Number of interrupts to getting error
 */
TEST( CheckTestGroup, CheckNumIntToGetError)
{
  u32 num_int_get_error= 15;
  CHECK_EQUAL(XST_SUCCESS, watchdog_cell_set_num_int_to_get_error(watchdog_dev,num_int_get_error));
  CHECK_EQUAL(num_int_get_error, data_reg[WATCHDOG_CELL_NUM_INT_ERROR_OFFSET]);
}
#endif


/*! \} */ // grouping



