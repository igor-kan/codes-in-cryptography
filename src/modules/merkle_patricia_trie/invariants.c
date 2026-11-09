/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for Cryptographic Merkle Patricia State Trie Engine.
 * Module: merkle_patricia_trie
 */

#include <assert.h>
#include <math.h>

static inline void merkle_patricia_trie_verify_invariant(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
