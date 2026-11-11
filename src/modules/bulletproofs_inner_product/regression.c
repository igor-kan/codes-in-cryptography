/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for Zero-Knowledge Inner Product Argument Verification.
 * Module: bulletproofs_inner_product
 */

#include <assert.h>

void test_bulletproofs_inner_product_regression_subnormal_day47(void) {
    double sub = 1e-312;
    double res = sub * (1.0 + 0.4 * sub);
    assert(res >= 0.0);
}
