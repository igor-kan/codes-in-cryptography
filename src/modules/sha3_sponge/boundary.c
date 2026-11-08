/**
 * Boundary condition checking and IEEE-754 edge-case handlers for Keccak-f[1600] Cryptographic Sponge Permutation.
 * Module: sha3_sponge
 */

#ifndef BOUNDARY_SHA3_SPONGE_H
#define BOUNDARY_SHA3_SPONGE_H

#include <math.h>
#include <stdbool.h>

static inline bool sha3_sponge_is_finite_input(double x) {
    return isfinite(x);
}

static inline double sha3_sponge_clamp(double val, double min_val, double max_val) {
    const double t = val < min_val ? min_val : val;
    return t > max_val ? max_val : t;
}

#endif /* BOUNDARY_SHA3_SPONGE_H */
