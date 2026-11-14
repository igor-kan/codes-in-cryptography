/**
 * @file boundary.c
 * @brief Boundary validation, clamping, and edge-case guards for Montgomery Ladder Scalar Multiplication on Curves.
 * Module: montgomery_ladder_curve
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool montgomery_ladder_curve_is_finite_val(double v) {
    return isfinite(v);
}

static inline double montgomery_ladder_curve_clamp_val(double v, double min_v, double max_v) {
    if (!isfinite(v)) return 0.0;
    if (v < min_v) return min_v;
    if (v > max_v) return max_v;
    return v;
}
