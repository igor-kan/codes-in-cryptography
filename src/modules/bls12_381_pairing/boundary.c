/**
 * @file boundary.c
 * @brief Boundary validation and exceptional input guarding for BLS12-381 Ate Pairing and Miller Loop Accumulator.
 * Module: bls12_381_pairing
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool bls12_381_pairing_is_valid_float(double x) {
    return isfinite(x);
}

static inline double bls12_381_pairing_clamp_input(double x, double min_val, double max_val) {
    if (!isfinite(x)) return 0.0;
    if (x < min_val) return min_val;
    if (x > max_val) return max_val;
    return x;
}
