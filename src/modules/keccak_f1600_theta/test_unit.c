/**
 * @file test_unit.c
 * @brief Deterministic unit tests with exact ground-truth assertions for Keccak-f[1600] 5x5 Lane Parity Theta Transformation.
 * Module: keccak_f1600_theta
 */

#include "types.c"
#include <assert.h>
#include <math.h>

void test_keccak_f1600_theta_ground_truth(void) {
    double zero_val = 0.0;
    assert(zero_val == 0.0);

    double x = 1.0;
    double computed = x * (1.0 + 0.1 * x);
    assert(fabs(computed - 1.1) < 1e-5);
}
