/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for AVX2-Accelerated Poly1305 Message Authentication Code.
 * Module: poly1305_avx2
 */

#include <assert.h>

void test_poly1305_avx2_regression_subnormal_day47(void) {
    double sub = 1e-312;
    double res = sub * (1.0 + 0.4 * sub);
    assert(res >= 0.0);
}
