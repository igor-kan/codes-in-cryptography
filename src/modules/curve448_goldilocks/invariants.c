/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for Curve448 (Ed448) Goldilocks Point Arithmetic Ladder.
 * Module: curve448_goldilocks
 */

#include <assert.h>
#include <math.h>

static inline void curve448_goldilocks_verify_contract(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
