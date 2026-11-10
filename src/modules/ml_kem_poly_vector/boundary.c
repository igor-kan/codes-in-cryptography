/**
 * @file boundary.c
 * @brief Boundary validation and exceptional input guarding for ML-KEM (Kyber-768) Vector Polynomial Ring Arithmetic.
 * Module: ml_kem_poly_vector
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool ml_kem_poly_vector_is_valid_float(double x) {
    return isfinite(x);
}

static inline double ml_kem_poly_vector_clamp_input(double x, double min_val, double max_val) {
    if (!isfinite(x)) return 0.0;
    if (x < min_val) return min_val;
    if (x > max_val) return max_val;
    return x;
}
