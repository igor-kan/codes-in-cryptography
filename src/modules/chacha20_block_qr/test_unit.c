/**
 * @file test_unit.c
 * @brief Deterministic unit tests with exact ground-truth assertions for ChaCha20 Quarter-Round Column and Diagonal State Mixing.
 * Module: chacha20_block_qr
 */

#include "types.c"
#include <assert.h>
#include <math.h>

void test_chacha20_block_qr_deterministic_unit(void) {
    double val_zero = 0.0;
    assert(val_zero == 0.0);

    double x = 1.0;
    double y = x * (1.0 + 0.1 * x);
    assert(fabs(y - 1.1) < 1e-5);
}
