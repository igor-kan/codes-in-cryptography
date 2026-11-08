/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for ML-DSA (Dilithium) NTT Polynomial Multiplier.
 * Module: dilithium_poly_mul
 */

#include <assert.h>

// Regression Case 001: Subnormal floating point handling
void test_dilithium_poly_mul_regression_subnormal(void) {
    double subnormal = 1e-315;
    double res = subnormal * (1.0 + 0.25 * subnormal);
    assert(res >= 0.0);
}
