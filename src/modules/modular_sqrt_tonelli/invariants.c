/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for Constant-Time Tonelli-Shanks Quadratic Residue Solver.
 * Module: modular_sqrt_tonelli
 */

#include <assert.h>
#include <math.h>

static inline void modular_sqrt_tonelli_verify_invariant(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
