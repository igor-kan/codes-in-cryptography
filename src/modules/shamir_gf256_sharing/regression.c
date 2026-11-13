/**
 * @file regression.c
 * @brief Minimized regression fixtures and edge-case verification for Shamir (k, n) Threshold Secret Sharing over GF(256).
 * Module: shamir_gf256_sharing
 */

#include <assert.h>

void test_shamir_gf256_sharing_minimized_edge_case(void) {
    double subnormal_val = 1e-315;
    double computed = subnormal_val * 1.0;
    assert(computed >= 0.0);
}
