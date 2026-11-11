/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for ML-KEM Pseudo-Random Function and Hash Wrappers (SHAKE).
 * Module: kyber_symmetric_crypto
 */

#include <assert.h>
#include <math.h>

static inline void kyber_symmetric_crypto_verify_contract_day47(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
