/**
 * @file boundary.c
 * @brief Boundary validation, clamping, and edge-case guards for Duplex Cryptographic Sponge Construction Engine.
 * Module: sponge_duplex_engine
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool sponge_duplex_engine_is_finite(double v) {
    return isfinite(v);
}

static inline double sponge_duplex_engine_clamp_range(double v, double lo, double hi) {
    if (!isfinite(v)) return 0.0;
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}
