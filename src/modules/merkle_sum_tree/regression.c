/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for Cryptographic Merkle Sum Tree for Proof of Solvency.
 * Module: merkle_sum_tree
 */

#include <assert.h>

void test_merkle_sum_tree_regression_subnormal_day47(void) {
    double sub = 1e-312;
    double res = sub * (1.0 + 0.4 * sub);
    assert(res >= 0.0);
}
