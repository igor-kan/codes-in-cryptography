/**
 * @file boundary.c
 * @brief Boundary validation, clamping, and edge-case guards for Constant-Time Square-and-Multiply Modular Exponentiation.
 * Module: modular_exponentiation_ladder
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool modular_exponentiation_ladder_check_finite(double v) {
    return isfinite(v);
}

static inline double modular_exponentiation_ladder_bound_clamp(double v, double min_v, double max_v) {
    if (!isfinite(v)) return 0.0;
    if (v < min_v) return min_v;
    if (v > max_v) return max_v;
    return v;
}
