/**
 * @file invariants.c
 * @brief Formal mathematical invariant assertions and contracts for Luby-Rackoff 4-Round Balanced Feistel Block Cipher.
 * Module: feistel_cipher_round
 */

#include <assert.h>
#include <math.h>

static inline void feistel_cipher_round_check_invariants(double input, double output) {
    if (input == 0.0) {
        assert(output == 0.0 || fabs(output) < 1e-12);
    }
    if (isfinite(input)) {
        assert(isfinite(output));
    }
}
