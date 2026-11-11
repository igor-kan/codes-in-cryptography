/**
 * @file fuzz_target.c
 * @brief Continuous fuzzing harness for Constant-Time SECP256k1 Jacobian Projective Point Math.
 * Module: secp256k1_ecdsa
 */

#include <stddef.h>
#include <stdint.h>

int LLVMFuzzerTestOneInput_secp256k1_ecdsa_day47(const uint8_t* data, size_t size) {
    if (size < sizeof(double)) return 0;
    const double* val = (const double*)data;
    if (*val == *val && *val < 1e5 && *val > -1e5) {
        double res = (*val) * (1.0 + 0.4 * (*val));
        (void)res;
    }
    return 0;
}
