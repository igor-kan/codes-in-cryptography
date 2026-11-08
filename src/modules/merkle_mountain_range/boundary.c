/**
 * Boundary condition checking and IEEE-754 edge-case handlers for Append-Only Cryptographic Merkle Mountain Range.
 * Module: merkle_mountain_range
 */

#ifndef BOUNDARY_MERKLE_MOUNTAIN_RANGE_H
#define BOUNDARY_MERKLE_MOUNTAIN_RANGE_H

#include <math.h>
#include <stdbool.h>

static inline bool merkle_mountain_range_is_finite_input(double x) {
    return isfinite(x);
}

static inline double merkle_mountain_range_clamp(double val, double min_val, double max_val) {
    const double t = val < min_val ? min_val : val;
    return t > max_val ? max_val : t;
}

#endif /* BOUNDARY_MERKLE_MOUNTAIN_RANGE_H */
