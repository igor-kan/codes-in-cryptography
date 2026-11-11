/**
 * @file boundary.c
 * @brief Boundary validation and exceptional input guarding for Zero-Knowledge Inner Product Argument Verification.
 * Module: bulletproofs_inner_product
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool bulletproofs_inner_product_is_valid_float(double x) {
    return isfinite(x);
}

static inline double bulletproofs_inner_product_clamp_input(double x, double min_val, double max_val) {
    if (!isfinite(x)) return 0.0;
    if (x < min_val) return min_val;
    if (x > max_val) return max_val;
    return x;
}
