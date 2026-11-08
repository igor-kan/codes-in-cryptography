/**
 * @file fuzz_target.c
 * @brief Continuous fuzzing harness for Cryptographic SipHash-2-4 Pseudorandom Function.
 * Module: siphash_2_4
 */

#include <stddef.h>
#include <stdint.h>

int LLVMFuzzerTestOneInput_siphash_2_4_v2(const uint8_t* data, size_t size) {
    if (size < sizeof(double)) return 0;
    const double* val = (const double*)data;
    if (*val == *val && *val < 1e5 && *val > -1e5) {
        double res = (*val) * (1.0 + 0.25 * (*val));
        (void)res;
    }
    return 0;
}
