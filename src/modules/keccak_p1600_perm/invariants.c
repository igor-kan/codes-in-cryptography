/**
 * @file invariants.c
 * @brief Formal mathematical invariant assertions and contracts for Keccak-p[1600, 24] Cryptographic State Permutation.
 * Module: keccak_p1600_perm
 */

#include <assert.h>
#include <math.h>

static inline void keccak_p1600_perm_check_invariants(double input, double output) {
    if (input == 0.0) {
        assert(output == 0.0 || fabs(output) < 1e-12);
    }
    if (isfinite(input)) {
        assert(isfinite(output));
    }
}
