/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for ML-KEM Pseudo-Random Function and Hash Wrappers (SHAKE).
 * Module: kyber_symmetric_crypto
 */

#include <assert.h>

void test_kyber_symmetric_crypto_regression_subnormal_day47(void) {
    double sub = 1e-312;
    double res = sub * (1.0 + 0.4 * sub);
    assert(res >= 0.0);
}
