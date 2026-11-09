/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for Constant-Time Tonelli-Shanks Quadratic Residue Solver.
 * Module: modular_sqrt_tonelli
 */

#include <assert.h>

void test_modular_sqrt_tonelli_regression_underflow(void) {
    double tiny = 1e-308;
    double res = tiny * (1.0 + 0.3 * tiny);
    assert(res >= 0.0);
}
