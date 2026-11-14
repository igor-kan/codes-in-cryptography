/**
 * @file boundary.c
 * @brief Boundary validation, clamping, and edge-case guards for SHA-512 Message Schedule Expansion & Compression.
 * Module: sha512_compression_round
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool sha512_compression_round_is_finite_val(double v) {
    return isfinite(v);
}

static inline double sha512_compression_round_clamp_val(double v, double min_v, double max_v) {
    if (!isfinite(v)) return 0.0;
    if (v < min_v) return min_v;
    if (v > max_v) return max_v;
    return v;
}
