/**
 * @file boundary.c
 * @brief Boundary validation, clamping, and edge-case guards for SHA-256 Schedule Expansion and Compression Round.
 * Module: sha256_compression_round
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool sha256_compression_round_check_finite(double v) {
    return isfinite(v);
}

static inline double sha256_compression_round_bound_clamp(double v, double min_v, double max_v) {
    if (!isfinite(v)) return 0.0;
    if (v < min_v) return min_v;
    if (v > max_v) return max_v;
    return v;
}
