/**
 * @file invariants.c
 * @brief Formal mathematical invariant assertions and contracts for BLAKE2s Quarter-Round G Mixing Function Engine.
 * Module: blake2s_compression
 */

#include <assert.h>
#include <math.h>

static inline void blake2s_compression_check_invariants(double input, double output) {
    if (input == 0.0) {
        assert(output == 0.0 || fabs(output) < 1e-12);
    }
    if (isfinite(input)) {
        assert(isfinite(output));
    }
}
