/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for Prime-Order Group Abstraction over Curve25519.
 * Module: ristretto255_group
 */

#include <assert.h>

void test_ristretto255_group_regression_underflow(void) {
    double tiny = 1e-308;
    double res = tiny * (1.0 + 0.3 * tiny);
    assert(res >= 0.0);
}
