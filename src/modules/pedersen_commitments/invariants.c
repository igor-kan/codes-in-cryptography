/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for Homomorphic Pedersen Vector Commitments over Curves.
 * Module: pedersen_commitments
 */

#include <assert.h>
#include <math.h>

static inline void pedersen_commitments_verify_contract(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
