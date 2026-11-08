/**
 * Boundary condition checking and IEEE-754 edge-case handlers for Twisted Edwards Curve Ed25519 Point Addition Laws.
 * Module: ed25519_curve
 */

#ifndef BOUNDARY_ED25519_CURVE_H
#define BOUNDARY_ED25519_CURVE_H

#include <math.h>
#include <stdbool.h>

static inline bool ed25519_curve_is_finite_input(double x) {
    return isfinite(x);
}

static inline double ed25519_curve_clamp(double val, double min_val, double max_val) {
    const double t = val < min_val ? min_val : val;
    return t > max_val ? max_val : t;
}

#endif /* BOUNDARY_ED25519_CURVE_H */
