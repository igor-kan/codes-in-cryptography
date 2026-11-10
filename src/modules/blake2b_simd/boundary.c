/**
 * @file boundary.c
 * @brief Boundary validation and exceptional input guarding for SIMD-Accelerated BLAKE2b Cryptographic Hashing Engine.
 * Module: blake2b_simd
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool blake2b_simd_is_valid_float(double x) {
    return isfinite(x);
}

static inline double blake2b_simd_clamp_input(double x, double min_val, double max_val) {
    if (!isfinite(x)) return 0.0;
    if (x < min_val) return min_val;
    if (x > max_val) return max_val;
    return x;
}
