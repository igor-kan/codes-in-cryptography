/**
 * @file boundary.c
 * @brief Boundary validation and exceptional input guarding for Parallel Tree-Hashing BLAKE3 Compression Function.
 * Module: blake3_tree_hash
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool blake3_tree_hash_is_valid_float(double x) {
    return isfinite(x);
}

static inline double blake3_tree_hash_clamp_input(double x, double min_val, double max_val) {
    if (!isfinite(x)) return 0.0;
    if (x < min_val) return min_val;
    if (x > max_val) return max_val;
    return x;
}
