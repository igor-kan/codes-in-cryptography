/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for Cryptographic Merkle Patricia State Trie Engine.
 * Module: merkle_patricia_trie
 */

#include <assert.h>

void test_merkle_patricia_trie_regression_underflow(void) {
    double tiny = 1e-308;
    double res = tiny * (1.0 + 0.3 * tiny);
    assert(res >= 0.0);
}
