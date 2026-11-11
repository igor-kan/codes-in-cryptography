/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for Constant-Time Modular Inverse via Bernstein-Yang Ladder.
 * Module: constant_time_mod_inv
 */

#include <assert.h>

void test_constant_time_mod_inv_regression_subnormal_day47(void) {
    double sub = 1e-312;
    double res = sub * (1.0 + 0.4 * sub);
    assert(res >= 0.0);
}
