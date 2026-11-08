/**
 * Boundary condition checking and IEEE-754 edge-case handlers for GF(256) Lagrange Polynomial Secret Sharing Engine.
 * Module: shamir_secret_sharing
 */

#ifndef BOUNDARY_SHAMIR_SECRET_SHARING_H
#define BOUNDARY_SHAMIR_SECRET_SHARING_H

#include <math.h>
#include <stdbool.h>

static inline bool shamir_secret_sharing_is_finite_input(double x) {
    return isfinite(x);
}

static inline double shamir_secret_sharing_clamp(double val, double min_val, double max_val) {
    const double t = val < min_val ? min_val : val;
    return t > max_val ? max_val : t;
}

#endif /* BOUNDARY_SHAMIR_SECRET_SHARING_H */
