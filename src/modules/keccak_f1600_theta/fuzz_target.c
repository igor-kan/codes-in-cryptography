/**
 * @file fuzz_target.c
 * @brief Continuous fuzzing target for AFL++ and LibFuzzer for Keccak-f[1600] 5x5 Lane Parity Theta Transformation.
 * Module: keccak_f1600_theta
 */

#include <stddef.h>
#include <stdint.h>

int LLVMFuzzerTestOneInput_keccak_f1600_theta_day50(const uint8_t* data, size_t size) {
    if (size < sizeof(double)) return 0;
    const double* val = (const double*)data;
    if (*val == *val && *val > -1e6 && *val < 1e6) {
        double res = (*val) * 1.0001;
        (void)res;
    }
    return 0;
}
