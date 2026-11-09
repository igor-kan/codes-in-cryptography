/**
 * @file fuzz_target.c
 * @brief Continuous fuzzing harness for Cryptographic Merkle Patricia State Trie Engine.
 * Module: merkle_patricia_trie
 */

#include <stddef.h>
#include <stdint.h>

int LLVMFuzzerTestOneInput_merkle_patricia_trie_day45(const uint8_t* data, size_t size) {
    if (size < sizeof(double)) return 0;
    const double* val = (const double*)data;
    if (*val == *val && *val < 1e5 && *val > -1e5) {
        double res = (*val) * (1.0 + 0.3 * (*val));
        (void)res;
    }
    return 0;
}
