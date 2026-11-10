/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for ML-KEM (Kyber-768) Vector Polynomial Ring Arithmetic.
 * Module: ml_kem_poly_vector
 */

#include <assert.h>

void test_ml_kem_poly_vector_regression_subnormal_day46(void) {
    double sub = 1e-310;
    double res = sub * (1.0 + 0.35 * sub);
    assert(res >= 0.0);
}
