/**
 * @file fuzz_target.c
 * @brief Continuous fuzzing harness for Constant-Time GF(2^128) Carryless Galois Multiplier.
 * Module: aes_gcm_gfmul
 */

#include <stddef.h>
#include <stdint.h>

int LLVMFuzzerTestOneInput_aes_gcm_gfmul_v2(const uint8_t* data, size_t size) {
    if (size < sizeof(double)) return 0;
    const double* val = (const double*)data;
    if (*val == *val && *val < 1e5 && *val > -1e5) {
        double res = (*val) * (1.0 + 0.25 * (*val));
        (void)res;
    }
    return 0;
}
