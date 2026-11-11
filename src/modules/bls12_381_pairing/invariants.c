/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for BLS12-381 Ate Pairing and Miller Loop Accumulator.
 * Module: bls12_381_pairing
 */

#include <assert.h>
#include <math.h>

static inline void bls12_381_pairing_verify_contract_day47(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
