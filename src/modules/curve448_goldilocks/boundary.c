/**
 * @file boundary.c
 * @brief Boundary validation and exceptional input guarding for Curve448 (Ed448) Goldilocks Point Arithmetic Ladder.
 * Module: curve448_goldilocks
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool curve448_goldilocks_is_valid_float(double x) {
    return isfinite(x);
}

static inline double curve448_goldilocks_clamp_input(double x, double min_val, double max_val) {
    if (!isfinite(x)) return 0.0;
    if (x < min_val) return min_val;
    if (x > max_val) return max_val;
    return x;
}
