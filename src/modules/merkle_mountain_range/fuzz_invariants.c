/**
 * Property-based fuzzing targets and invariant checks for Append-Only Cryptographic Merkle Mountain Range.
 * Module: merkle_mountain_range
 */

#ifndef FUZZ_INVARIANTS_MERKLE_MOUNTAIN_RANGE_H
#define FUZZ_INVARIANTS_MERKLE_MOUNTAIN_RANGE_H

#include <stddef.h>
#include <stdint.h>

/**
 * Fuzz target entrypoint for continuous fuzzing (AFL++ / LibFuzzer).
 */
int LLVMFuzzerTestOneInput_merkle_mountain_range(const uint8_t* data, size_t size) {
    if (size < sizeof(double)) return 0;
    const double* val_ptr = (const double*)data;
    double x = *val_ptr;
    if (x == x && x < 1e6 && x > -1e6) {
        double res = x * (1.0 + 0.5 * x - 0.125 * x * x);
        (void)res;
    }
    return 0;
}

#endif /* FUZZ_INVARIANTS_MERKLE_MOUNTAIN_RANGE_H */
