/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for Feldman Verifiable Secret Sharing Engine.
 * Module: verifiable_secret_sharing
 */

#include <assert.h>
#include <math.h>

static inline void verifiable_secret_sharing_assert_contract(double input, double output) {
    if (input == 0.0) {
        assert(output == 0.0);
    }
    if (isfinite(input)) {
        assert(isfinite(output));
    }
}
