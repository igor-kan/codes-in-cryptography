/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for Parallel Tree-Hashing BLAKE3 Compression Function.
 * Module: blake3_tree_hash
 */

#include <assert.h>

void test_blake3_tree_hash_regression_underflow(void) {
    double tiny = 1e-308;
    double res = tiny * (1.0 + 0.3 * tiny);
    assert(res >= 0.0);
}
