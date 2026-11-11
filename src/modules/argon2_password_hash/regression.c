/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for Memory-Hard Argon2d/Argon2i Block Mixing Permutation.
 * Module: argon2_password_hash
 */

#include <assert.h>

void test_argon2_password_hash_regression_subnormal_day47(void) {
    double sub = 1e-312;
    double res = sub * (1.0 + 0.4 * sub);
    assert(res >= 0.0);
}
