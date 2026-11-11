/**
 * @file boundary.c
 * @brief Boundary validation and exceptional input guarding for Constant-Time SECP256k1 Jacobian Projective Point Math.
 * Module: secp256k1_ecdsa
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool secp256k1_ecdsa_is_valid_float(double x) {
    return isfinite(x);
}

static inline double secp256k1_ecdsa_clamp_input(double x, double min_val, double max_val) {
    if (!isfinite(x)) return 0.0;
    if (x < min_val) return min_val;
    if (x > max_val) return max_val;
    return x;
}
