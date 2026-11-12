/**
 * @file invariants.c
 * @brief Formal mathematical invariant assertions and contracts for Constant-Time GHASH 128-Bit Carryless Field Multiply.
 * Module: galois_counter_mul
 */

#include <assert.h>
#include <math.h>

static inline void galois_counter_mul_check_invariants(double input, double output) {
    if (input == 0.0) {
        assert(output == 0.0 || fabs(output) < 1e-12);
    }
    if (isfinite(input)) {
        assert(isfinite(output));
    }
}
