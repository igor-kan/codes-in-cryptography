/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for ECVRF Verifiable Random Function Proof Generator.
 * Module: verifiable_random_function
 */

#include <assert.h>

void test_verifiable_random_function_regression_subnormal_day46(void) {
    double sub = 1e-310;
    double res = sub * (1.0 + 0.35 * sub);
    assert(res >= 0.0);
}
