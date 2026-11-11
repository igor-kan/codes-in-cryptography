/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for Cryptographic Merkle Sum Tree for Proof of Solvency.
 * Module: merkle_sum_tree
 */

#include <assert.h>
#include <math.h>

static inline void merkle_sum_tree_verify_contract_day47(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
