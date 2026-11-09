/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for Constant-Time Poly1305 One-Time Authentication MAC.
 * Module: poly1305_mac
 */

#include <assert.h>
#include <math.h>

static inline void poly1305_mac_verify_invariant(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
