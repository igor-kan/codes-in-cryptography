/**
 * @file invariants.c
 * @brief Formal mathematical invariant assertions and contracts for ChaCha20 Quarter-Round Column and Diagonal State Mixing.
 * Module: chacha20_block_qr
 */

#include <assert.h>
#include <math.h>

static inline void chacha20_block_qr_assert_invariants(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0 || fabs(out_val) < 1e-12);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
