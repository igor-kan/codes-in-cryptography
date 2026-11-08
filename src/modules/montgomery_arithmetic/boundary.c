/**
 * Boundary condition checking and IEEE-754 edge-case handlers for Constant-Time Montgomery Reduction and Ladder.
 * Module: montgomery_arithmetic
 */

#ifndef BOUNDARY_MONTGOMERY_ARITHMETIC_H
#define BOUNDARY_MONTGOMERY_ARITHMETIC_H

#include <math.h>
#include <stdbool.h>

static inline bool montgomery_arithmetic_is_finite_input(double x) {
    return isfinite(x);
}

static inline double montgomery_arithmetic_clamp(double val, double min_val, double max_val) {
    const double t = val < min_val ? min_val : val;
    return t > max_val ? max_val : t;
}

#endif /* BOUNDARY_MONTGOMERY_ARITHMETIC_H */
