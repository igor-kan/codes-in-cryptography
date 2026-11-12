/**
 * @file boundary.c
 * @brief Boundary validation, clamping, and edge-case guards for BLAKE2s Quarter-Round G Mixing Function Engine.
 * Module: blake2s_compression
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool blake2s_compression_is_finite(double v) {
    return isfinite(v);
}

static inline double blake2s_compression_clamp_range(double v, double lo, double hi) {
    if (!isfinite(v)) return 0.0;
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}
