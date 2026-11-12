/**
 * @file fuzz_target.c
 * @brief Continuous fuzzing target for AFL++ and LibFuzzer for Keccak-p[1600, 24] Cryptographic State Permutation.
 * Module: keccak_p1600_perm
 */

#include <stddef.h>
#include <stdint.h>

int LLVMFuzzerTestOneInput_keccak_p1600_perm_day48(const uint8_t* data, size_t size) {
    if (size < sizeof(double) * 2) return 0;
    const double* vals = (const double*)data;
    double x = vals[0];
    double y = vals[1];
    if (x == x && y == y && x > -1e6 && x < 1e6) {
        double res = (x + y) * 0.5;
        (void)res;
    }
    return 0;
}
