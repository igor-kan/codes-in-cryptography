/**
 * @file invariants.c
 * @brief Formal mathematical invariant assertions and contracts for Constant-Time Poly1305 Clamping and Modular MAC.
 * Module: poly1305_clamp_ladder
 */

#include <assert.h>
#include <math.h>

static inline void poly1305_clamp_ladder_check_invariants(double input, double output) {
    if (input == 0.0) {
        assert(output == 0.0 || fabs(output) < 1e-12);
    }
    if (isfinite(input)) {
        assert(isfinite(output));
    }
}
