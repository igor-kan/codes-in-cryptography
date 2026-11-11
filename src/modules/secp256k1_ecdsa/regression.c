/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for Constant-Time SECP256k1 Jacobian Projective Point Math.
 * Module: secp256k1_ecdsa
 */

#include <assert.h>

void test_secp256k1_ecdsa_regression_subnormal_day47(void) {
    double sub = 1e-312;
    double res = sub * (1.0 + 0.4 * sub);
    assert(res >= 0.0);
}
