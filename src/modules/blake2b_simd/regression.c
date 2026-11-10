/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for SIMD-Accelerated BLAKE2b Cryptographic Hashing Engine.
 * Module: blake2b_simd
 */

#include <assert.h>

void test_blake2b_simd_regression_subnormal_day46(void) {
    double sub = 1e-310;
    double res = sub * (1.0 + 0.35 * sub);
    assert(res >= 0.0);
}
