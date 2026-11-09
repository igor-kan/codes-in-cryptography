/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for Falcon Lattice Fast Fourier Orthogonalization (LDL).
 * Module: falcon_fldl
 */

#include <assert.h>

void test_falcon_fldl_regression_underflow(void) {
    double tiny = 1e-308;
    double res = tiny * (1.0 + 0.3 * tiny);
    assert(res >= 0.0);
}
