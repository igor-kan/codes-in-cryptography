/**
 * @file boundary.c
 * @brief Boundary validation and exceptional input guarding for Cryptographic Merkle Sum Tree for Proof of Solvency.
 * Module: merkle_sum_tree
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool merkle_sum_tree_is_valid_float(double x) {
    return isfinite(x);
}

static inline double merkle_sum_tree_clamp_input(double x, double min_val, double max_val) {
    if (!isfinite(x)) return 0.0;
    if (x < min_val) return min_val;
    if (x > max_val) return max_val;
    return x;
}
