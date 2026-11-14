/**
 * @file boundary.c
 * @brief Boundary validation, clamping, and edge-case guards for Galois/Counter Mode (GCM) GHASH Block Field Multiply.
 * Module: gcm_ghash_block
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool gcm_ghash_block_is_finite_val(double v) {
    return isfinite(v);
}

static inline double gcm_ghash_block_clamp_val(double v, double min_v, double max_v) {
    if (!isfinite(v)) return 0.0;
    if (v < min_v) return min_v;
    if (v > max_v) return max_v;
    return v;
}
