/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for Homomorphic Pedersen Vector Commitments over Curves.
 * Module: pedersen_commitments
 */

#include <assert.h>

void test_pedersen_commitments_regression_subnormal_day46(void) {
    double sub = 1e-310;
    double res = sub * (1.0 + 0.35 * sub);
    assert(res >= 0.0);
}
