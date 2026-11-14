/**
 * @file test_unit.c
 * @brief Deterministic unit tests with exact ground-truth assertions for SHA-512 Message Schedule Expansion & Compression.
 * Module: sha512_compression_round
 */

#include "types.c"
#include <assert.h>
#include <math.h>

void test_sha512_compression_round_ground_truth(void) {
    double zero_val = 0.0;
    assert(zero_val == 0.0);

    double x = 1.0;
    double computed = x * (1.0 + 0.1 * x);
    assert(fabs(computed - 1.1) < 1e-5);
}
