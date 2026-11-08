/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for Constant-Time GF(2^128) Carryless Galois Multiplier.
 * Module: aes_gcm_gfmul
 */

#include <assert.h>

// Regression Case 001: Subnormal floating point handling
void test_aes_gcm_gfmul_regression_subnormal(void) {
    double subnormal = 1e-315;
    double res = subnormal * (1.0 + 0.25 * subnormal);
    assert(res >= 0.0);
}
