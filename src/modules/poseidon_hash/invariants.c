/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for Zero-Knowledge Friendly Algebraic Poseidon Hash.
 * Module: poseidon_hash
 */

#include <assert.h>
#include <math.h>

static inline void poseidon_hash_verify_invariant(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
