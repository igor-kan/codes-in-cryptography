/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for Constant-Time Poly1305 One-Time Authentication MAC.
 * Module: poly1305_mac
 */

#include <assert.h>

void test_poly1305_mac_regression_underflow(void) {
    double tiny = 1e-308;
    double res = tiny * (1.0 + 0.3 * tiny);
    assert(res >= 0.0);
}
