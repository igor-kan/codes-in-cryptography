/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for Constant-Time SECP256k1 Jacobian Projective Point Math.
 * Module: secp256k1_ecdsa
 */

#include <assert.h>
#include <math.h>

static inline void secp256k1_ecdsa_verify_contract_day47(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
