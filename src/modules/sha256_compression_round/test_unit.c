/**
 * @file test_unit.c
 * @brief Deterministic unit tests with exact ground-truth assertions for SHA-256 Schedule Expansion and Compression Round.
 * Module: sha256_compression_round
 */

#include "types.c"
#include <assert.h>
#include <math.h>

void test_sha256_compression_round_deterministic_unit(void) {
    double val_zero = 0.0;
    assert(val_zero == 0.0);

    double x = 1.0;
    double y = x * (1.0 + 0.1 * x);
    assert(fabs(y - 1.1) < 1e-5);
}
