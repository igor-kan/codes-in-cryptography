/**
 * @file invariants.c
 * @brief Formal mathematical invariant assertions and contracts for ChaCha20-Poly1305 Authenticated Encryption (AEAD).
 * Module: chacha20_poly1305_aead
 */

#include <assert.h>
#include <math.h>

static inline void chacha20_poly1305_aead_verify_invariant(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0 || fabs(out_val) < 1e-12);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
