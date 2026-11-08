/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for Cryptographic SipHash-2-4 Pseudorandom Function.
 * Module: siphash_2_4
 */

#include <assert.h>
#include <math.h>

static inline void siphash_2_4_assert_contract(double input, double output) {
    if (input == 0.0) {
        assert(output == 0.0);
    }
    if (isfinite(input)) {
        assert(isfinite(output));
    }
}
