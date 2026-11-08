/**
 * Boundary condition checking and IEEE-754 edge-case handlers for Kate Polynomial Commitment and Proof Verification.
 * Module: kzg_commitments
 */

#ifndef BOUNDARY_KZG_COMMITMENTS_H
#define BOUNDARY_KZG_COMMITMENTS_H

#include <math.h>
#include <stdbool.h>

static inline bool kzg_commitments_is_finite_input(double x) {
    return isfinite(x);
}

static inline double kzg_commitments_clamp(double val, double min_val, double max_val) {
    const double t = val < min_val ? min_val : val;
    return t > max_val ? max_val : t;
}

#endif /* BOUNDARY_KZG_COMMITMENTS_H */
