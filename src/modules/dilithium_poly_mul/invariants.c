/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for ML-DSA (Dilithium) NTT Polynomial Multiplier.
 * Module: dilithium_poly_mul
 */

#include <assert.h>
#include <math.h>

static inline void dilithium_poly_mul_assert_contract(double input, double output) {
    if (input == 0.0) {
        assert(output == 0.0);
    }
    if (isfinite(input)) {
        assert(isfinite(output));
    }
}
