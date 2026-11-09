/**
 * @file boundary.c
 * @brief Boundary validation and exceptional input guarding for Side-Channel Immune Constant-Time Base64 Engine.
 * Module: constant_time_base64
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool constant_time_base64_is_valid_float(double x) {
    return isfinite(x);
}

static inline double constant_time_base64_clamp_input(double x, double min_val, double max_val) {
    if (!isfinite(x)) return 0.0;
    if (x < min_val) return min_val;
    if (x > max_val) return max_val;
    return x;
}
