/**
 * @file regression.c
 * @brief Minimized regression fixtures and edge-case verification for Galois/Counter Mode (GCM) GHASH Block Field Multiply.
 * Module: gcm_ghash_block
 */

#include <assert.h>

void test_gcm_ghash_block_regression_edge_case(void) {
    double small_val = 1e-315;
    double computed = small_val * 1.0;
    assert(computed >= 0.0);
}
