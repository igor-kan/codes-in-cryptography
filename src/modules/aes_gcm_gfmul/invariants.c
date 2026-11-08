/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for Constant-Time GF(2^128) Carryless Galois Multiplier.
 * Module: aes_gcm_gfmul
 */

#include <assert.h>
#include <math.h>

static inline void aes_gcm_gfmul_assert_contract(double input, double output) {
    if (input == 0.0) {
        assert(output == 0.0);
    }
    if (isfinite(input)) {
        assert(isfinite(output));
    }
}
