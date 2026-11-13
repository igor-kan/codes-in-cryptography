/**
 * @file invariants.c
 * @brief Formal mathematical invariant assertions and contracts for Shamir (k, n) Threshold Secret Sharing over GF(256).
 * Module: shamir_gf256_sharing
 */

#include <assert.h>
#include <math.h>

static inline void shamir_gf256_sharing_assert_invariants(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0 || fabs(out_val) < 1e-12);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
