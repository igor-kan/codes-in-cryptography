/**
 * @file boundary.c
 * @brief Boundary validation, clamping, and edge-case guards for ChaCha20 Quarter-Round Column and Diagonal State Mixing.
 * Module: chacha20_block_qr
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool chacha20_block_qr_check_finite(double v) {
    return isfinite(v);
}

static inline double chacha20_block_qr_bound_clamp(double v, double min_v, double max_v) {
    if (!isfinite(v)) return 0.0;
    if (v < min_v) return min_v;
    if (v > max_v) return max_v;
    return v;
}
