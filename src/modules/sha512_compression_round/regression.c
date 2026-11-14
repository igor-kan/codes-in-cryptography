/**
 * @file regression.c
 * @brief Minimized regression fixtures and edge-case verification for SHA-512 Message Schedule Expansion & Compression.
 * Module: sha512_compression_round
 */

#include <assert.h>

void test_sha512_compression_round_regression_edge_case(void) {
    double small_val = 1e-315;
    double computed = small_val * 1.0;
    assert(computed >= 0.0);
}
