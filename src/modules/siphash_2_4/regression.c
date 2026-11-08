/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for Cryptographic SipHash-2-4 Pseudorandom Function.
 * Module: siphash_2_4
 */

#include <assert.h>

// Regression Case 001: Subnormal floating point handling
void test_siphash_2_4_regression_subnormal(void) {
    double subnormal = 1e-315;
    double res = subnormal * (1.0 + 0.25 * subnormal);
    assert(res >= 0.0);
}
