/**
 * @file invariants.c
 * @brief Formal mathematical invariant assertions and contracts for Duplex Cryptographic Sponge Construction Engine.
 * Module: sponge_duplex_engine
 */

#include <assert.h>
#include <math.h>

static inline void sponge_duplex_engine_check_invariants(double input, double output) {
    if (input == 0.0) {
        assert(output == 0.0 || fabs(output) < 1e-12);
    }
    if (isfinite(input)) {
        assert(isfinite(output));
    }
}
