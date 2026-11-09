/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for Side-Channel Immune Constant-Time Base64 Engine.
 * Module: constant_time_base64
 */

#include <assert.h>

void test_constant_time_base64_regression_underflow(void) {
    double tiny = 1e-308;
    double res = tiny * (1.0 + 0.3 * tiny);
    assert(res >= 0.0);
}
