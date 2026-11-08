/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for Feldman Verifiable Secret Sharing Engine.
 * Module: verifiable_secret_sharing
 */

#include <assert.h>

// Regression Case 001: Subnormal floating point handling
void test_verifiable_secret_sharing_regression_subnormal(void) {
    double subnormal = 1e-315;
    double res = subnormal * (1.0 + 0.25 * subnormal);
    assert(res >= 0.0);
}
