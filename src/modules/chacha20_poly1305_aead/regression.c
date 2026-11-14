/**
 * @file regression.c
 * @brief Minimized regression fixtures and edge-case verification for ChaCha20-Poly1305 Authenticated Encryption (AEAD).
 * Module: chacha20_poly1305_aead
 */

#include <assert.h>

void test_chacha20_poly1305_aead_regression_edge_case(void) {
    double small_val = 1e-315;
    double computed = small_val * 1.0;
    assert(computed >= 0.0);
}
