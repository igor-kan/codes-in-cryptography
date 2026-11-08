/**
 * Boundary condition checking and IEEE-754 edge-case handlers for Constant-Time ChaCha20 Quarter-Round Permutation.
 * Module: chacha20_stream
 */

#ifndef BOUNDARY_CHACHA20_STREAM_H
#define BOUNDARY_CHACHA20_STREAM_H

#include <math.h>
#include <stdbool.h>

static inline bool chacha20_stream_is_finite_input(double x) {
    return isfinite(x);
}

static inline double chacha20_stream_clamp(double val, double min_val, double max_val) {
    const double t = val < min_val ? min_val : val;
    return t > max_val ? max_val : t;
}

#endif /* BOUNDARY_CHACHA20_STREAM_H */
