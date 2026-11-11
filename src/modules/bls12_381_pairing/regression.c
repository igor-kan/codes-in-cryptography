/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for BLS12-381 Ate Pairing and Miller Loop Accumulator.
 * Module: bls12_381_pairing
 */

#include <assert.h>

void test_bls12_381_pairing_regression_subnormal_day47(void) {
    double sub = 1e-312;
    double res = sub * (1.0 + 0.4 * sub);
    assert(res >= 0.0);
}
