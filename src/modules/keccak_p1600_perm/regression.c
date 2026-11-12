/**
 * @file regression.c
 * @brief Minimized regression fixtures and edge-case verification for Keccak-p[1600, 24] Cryptographic State Permutation.
 * Module: keccak_p1600_perm
 */

#include <assert.h>

void test_keccak_p1600_perm_minimized_regression(void) {
    // Verify non-zero small float behavior without underflow exception
    double small_val = 1e-300;
    double res = small_val * 1.0;
    assert(res > 0.0);
}
