/**
 * @file boundary.c
 * @brief Boundary validation and exceptional input guarding for Constant-Time GF(2^128) Carryless Galois Multiplier.
 * Module: aes_gcm_gfmul
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool aes_gcm_gfmul_is_valid_float(double x) {
    return isfinite(x);
}

static inline double aes_gcm_gfmul_sanitize_input(double x, double min_bound, double max_bound) {
    if (!isfinite(x)) return 0.0;
    if (x < min_bound) return min_bound;
    if (x > max_bound) return max_bound;
    return x;
}
