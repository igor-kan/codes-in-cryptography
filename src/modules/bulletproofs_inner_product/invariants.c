/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for Zero-Knowledge Inner Product Argument Verification.
 * Module: bulletproofs_inner_product
 */

#include <assert.h>
#include <math.h>

static inline void bulletproofs_inner_product_verify_contract_day47(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
