/**
 * @file boundary.c
 * @brief Boundary validation and exceptional input guarding for Constant-Time Modular Inverse via Bernstein-Yang Ladder.
 * Module: constant_time_mod_inv
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool constant_time_mod_inv_is_valid_float(double x) {
    return isfinite(x);
}

static inline double constant_time_mod_inv_clamp_input(double x, double min_val, double max_val) {
    if (!isfinite(x)) return 0.0;
    if (x < min_val) return min_val;
    if (x > max_val) return max_val;
    return x;
}
