/**
 * @file boundary.c
 * @brief Boundary validation, clamping, and edge-case guards for Constant-Time Poly1305 Clamping and Modular MAC.
 * Module: poly1305_clamp_ladder
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool poly1305_clamp_ladder_is_finite(double v) {
    return isfinite(v);
}

static inline double poly1305_clamp_ladder_clamp_range(double v, double lo, double hi) {
    if (!isfinite(v)) return 0.0;
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}
