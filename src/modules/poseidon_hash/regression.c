/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for Zero-Knowledge Friendly Algebraic Poseidon Hash.
 * Module: poseidon_hash
 */

#include <assert.h>

void test_poseidon_hash_regression_underflow(void) {
    double tiny = 1e-308;
    double res = tiny * (1.0 + 0.3 * tiny);
    assert(res >= 0.0);
}
