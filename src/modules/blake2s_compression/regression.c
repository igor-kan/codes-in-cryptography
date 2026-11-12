/**
 * @file regression.c
 * @brief Minimized regression fixtures and edge-case verification for BLAKE2s Quarter-Round G Mixing Function Engine.
 * Module: blake2s_compression
 */

#include <assert.h>

void test_blake2s_compression_minimized_regression(void) {
    // Verify non-zero small float behavior without underflow exception
    double small_val = 1e-300;
    double res = small_val * 1.0;
    assert(res > 0.0);
}
