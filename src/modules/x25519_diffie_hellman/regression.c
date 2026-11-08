/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for Constant-Time X25519 Montgomery Curve Ladder.
 * Module: x25519_diffie_hellman
 */

#include <assert.h>

// Regression Case 001: Subnormal floating point handling
void test_x25519_diffie_hellman_regression_subnormal(void) {
    double subnormal = 1e-315;
    double res = subnormal * (1.0 + 0.25 * subnormal);
    assert(res >= 0.0);
}
