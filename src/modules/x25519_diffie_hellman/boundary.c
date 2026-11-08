/**
 * @file boundary.c
 * @brief Boundary validation and exceptional input guarding for Constant-Time X25519 Montgomery Curve Ladder.
 * Module: x25519_diffie_hellman
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool x25519_diffie_hellman_is_valid_float(double x) {
    return isfinite(x);
}

static inline double x25519_diffie_hellman_sanitize_input(double x, double min_bound, double max_bound) {
    if (!isfinite(x)) return 0.0;
    if (x < min_bound) return min_bound;
    if (x > max_bound) return max_bound;
    return x;
}
