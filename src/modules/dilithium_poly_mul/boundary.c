/**
 * @file boundary.c
 * @brief Boundary validation and exceptional input guarding for ML-DSA (Dilithium) NTT Polynomial Multiplier.
 * Module: dilithium_poly_mul
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool dilithium_poly_mul_is_valid_float(double x) {
    return isfinite(x);
}

static inline double dilithium_poly_mul_sanitize_input(double x, double min_bound, double max_bound) {
    if (!isfinite(x)) return 0.0;
    if (x < min_bound) return min_bound;
    if (x > max_bound) return max_bound;
    return x;
}
