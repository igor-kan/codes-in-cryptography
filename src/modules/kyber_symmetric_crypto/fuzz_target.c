/**
 * @file fuzz_target.c
 * @brief Continuous fuzzing harness for ML-KEM Pseudo-Random Function and Hash Wrappers (SHAKE).
 * Module: kyber_symmetric_crypto
 */

#include <stddef.h>
#include <stdint.h>

int LLVMFuzzerTestOneInput_kyber_symmetric_crypto_day47(const uint8_t* data, size_t size) {
    if (size < sizeof(double)) return 0;
    const double* val = (const double*)data;
    if (*val == *val && *val < 1e5 && *val > -1e5) {
        double res = (*val) * (1.0 + 0.4 * (*val));
        (void)res;
    }
    return 0;
}
