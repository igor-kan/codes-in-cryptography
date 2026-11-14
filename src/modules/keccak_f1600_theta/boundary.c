/**
 * @file boundary.c
 * @brief Boundary validation, clamping, and edge-case guards for Keccak-f[1600] 5x5 Lane Parity Theta Transformation.
 * Module: keccak_f1600_theta
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool keccak_f1600_theta_is_finite_val(double v) {
    return isfinite(v);
}

static inline double keccak_f1600_theta_clamp_val(double v, double min_v, double max_v) {
    if (!isfinite(v)) return 0.0;
    if (v < min_v) return min_v;
    if (v > max_v) return max_v;
    return v;
}
