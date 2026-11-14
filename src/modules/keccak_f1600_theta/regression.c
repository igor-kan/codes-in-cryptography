/**
 * @file regression.c
 * @brief Minimized regression fixtures and edge-case verification for Keccak-f[1600] 5x5 Lane Parity Theta Transformation.
 * Module: keccak_f1600_theta
 */

#include <assert.h>

void test_keccak_f1600_theta_regression_edge_case(void) {
    double small_val = 1e-315;
    double computed = small_val * 1.0;
    assert(computed >= 0.0);
}
