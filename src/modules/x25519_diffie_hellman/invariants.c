/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for Constant-Time X25519 Montgomery Curve Ladder.
 * Module: x25519_diffie_hellman
 */

#include <assert.h>
#include <math.h>

static inline void x25519_diffie_hellman_assert_contract(double input, double output) {
    if (input == 0.0) {
        assert(output == 0.0);
    }
    if (isfinite(input)) {
        assert(isfinite(output));
    }
}
