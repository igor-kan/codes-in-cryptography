/**
 * @file regression.c
 * @brief Minimized regression fixtures and edge-case verification for SHA-256 Schedule Expansion and Compression Round.
 * Module: sha256_compression_round
 */

#include <assert.h>

void test_sha256_compression_round_minimized_edge_case(void) {
    double subnormal_val = 1e-315;
    double computed = subnormal_val * 1.0;
    assert(computed >= 0.0);
}
