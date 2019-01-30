/*!
 * \defgroup test
 * \brief    Sources for the unit tests of WatchDog Driver Cell driver
 * \author   Iván Albarrán
 * \{
 */

/*!
 * \file  main.cpp
 * \brief Main file of the project tests.
 */
#include <CppUTest/CommandLineTestRunner.h>

/*!
 * \brief Punto de entrada a los tests unitarios
 * \param ac
 * \param av
 * \return
 */
int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}

/*! \} */ // grouping
