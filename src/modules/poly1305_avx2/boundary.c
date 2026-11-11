/**
 * @file boundary.c
 * @brief Boundary validation and exceptional input guarding for AVX2-Accelerated Poly1305 Message Authentication Code.
 * Module: poly1305_avx2
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool poly1305_avx2_is_valid_float(double x) {
    return isfinite(x);
}

static inline double poly1305_avx2_clamp_input(double x, double min_val, double max_val) {
    if (!isfinite(x)) return 0.0;
    if (x < min_val) return min_val;
    if (x > max_val) return max_val;
    return x;
}
