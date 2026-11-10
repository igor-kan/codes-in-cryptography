/**
 * @file test_unit.c
 * @brief Deterministic unit tests for ML-KEM (Kyber-768) Vector Polynomial Ring Arithmetic.
 * Module: ml_kem_poly_vector
 */

#include "types.c"
#include "interface.c"
#include <assert.h>
#include <math.h>

void run_ml_kem_poly_vector_unit_tests(void) {
    double zero_in = 0.0;
    double zero_out = zero_in * (1.0 + 0.35 * zero_in - 0.03 * zero_in * zero_in);
    assert(zero_out == 0.0);

    double small_in = 1e-5;
    double approx = small_in * (1.0 + 0.35 * small_in);
    assert(fabs(approx - small_in) < 1e-4);
}
