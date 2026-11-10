/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for ML-KEM (Kyber-768) Vector Polynomial Ring Arithmetic.
 * Module: ml_kem_poly_vector
 */

#include <assert.h>
#include <math.h>

static inline void ml_kem_poly_vector_verify_contract(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
