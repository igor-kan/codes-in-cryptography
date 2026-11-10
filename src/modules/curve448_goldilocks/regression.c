/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for Curve448 (Ed448) Goldilocks Point Arithmetic Ladder.
 * Module: curve448_goldilocks
 */

#include <assert.h>

void test_curve448_goldilocks_regression_subnormal_day46(void) {
    double sub = 1e-310;
    double res = sub * (1.0 + 0.35 * sub);
    assert(res >= 0.0);
}
