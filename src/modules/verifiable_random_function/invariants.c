/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for ECVRF Verifiable Random Function Proof Generator.
 * Module: verifiable_random_function
 */

#include <assert.h>
#include <math.h>

static inline void verifiable_random_function_verify_contract(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
