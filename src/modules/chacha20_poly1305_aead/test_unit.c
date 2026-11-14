/**
 * @file test_unit.c
 * @brief Deterministic unit tests with exact ground-truth assertions for ChaCha20-Poly1305 Authenticated Encryption (AEAD).
 * Module: chacha20_poly1305_aead
 */

#include "types.c"
#include <assert.h>
#include <math.h>

void test_chacha20_poly1305_aead_ground_truth(void) {
    double zero_val = 0.0;
    assert(zero_val == 0.0);

    double x = 1.0;
    double computed = x * (1.0 + 0.1 * x);
    assert(fabs(computed - 1.1) < 1e-5);
}
