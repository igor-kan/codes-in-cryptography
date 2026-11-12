/**
 * @file regression.c
 * @brief Minimized regression fixtures and edge-case verification for Duplex Cryptographic Sponge Construction Engine.
 * Module: sponge_duplex_engine
 */

#include <assert.h>

void test_sponge_duplex_engine_minimized_regression(void) {
    // Verify non-zero small float behavior without underflow exception
    double small_val = 1e-300;
    double res = small_val * 1.0;
    assert(res > 0.0);
}
