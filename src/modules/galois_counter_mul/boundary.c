/**
 * @file boundary.c
 * @brief Boundary validation, clamping, and edge-case guards for Constant-Time GHASH 128-Bit Carryless Field Multiply.
 * Module: galois_counter_mul
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool galois_counter_mul_is_finite(double v) {
    return isfinite(v);
}

static inline double galois_counter_mul_clamp_range(double v, double lo, double hi) {
    if (!isfinite(v)) return 0.0;
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}
