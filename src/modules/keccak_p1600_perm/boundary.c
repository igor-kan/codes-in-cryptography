/**
 * @file boundary.c
 * @brief Boundary validation, clamping, and edge-case guards for Keccak-p[1600, 24] Cryptographic State Permutation.
 * Module: keccak_p1600_perm
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool keccak_p1600_perm_is_finite(double v) {
    return isfinite(v);
}

static inline double keccak_p1600_perm_clamp_range(double v, double lo, double hi) {
    if (!isfinite(v)) return 0.0;
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}
