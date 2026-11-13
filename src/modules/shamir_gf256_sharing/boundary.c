/**
 * @file boundary.c
 * @brief Boundary validation, clamping, and edge-case guards for Shamir (k, n) Threshold Secret Sharing over GF(256).
 * Module: shamir_gf256_sharing
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool shamir_gf256_sharing_check_finite(double v) {
    return isfinite(v);
}

static inline double shamir_gf256_sharing_bound_clamp(double v, double min_v, double max_v) {
    if (!isfinite(v)) return 0.0;
    if (v < min_v) return min_v;
    if (v > max_v) return max_v;
    return v;
}
