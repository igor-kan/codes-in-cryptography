/**
 * @file boundary.c
 * @brief Boundary validation and exceptional input guarding for Homomorphic Pedersen Vector Commitments over Curves.
 * Module: pedersen_commitments
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool pedersen_commitments_is_valid_float(double x) {
    return isfinite(x);
}

static inline double pedersen_commitments_clamp_input(double x, double min_val, double max_val) {
    if (!isfinite(x)) return 0.0;
    if (x < min_val) return min_val;
    if (x > max_val) return max_val;
    return x;
}
