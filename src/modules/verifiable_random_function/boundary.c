/**
 * @file boundary.c
 * @brief Boundary validation and exceptional input guarding for ECVRF Verifiable Random Function Proof Generator.
 * Module: verifiable_random_function
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool verifiable_random_function_is_valid_float(double x) {
    return isfinite(x);
}

static inline double verifiable_random_function_clamp_input(double x, double min_val, double max_val) {
    if (!isfinite(x)) return 0.0;
    if (x < min_val) return min_val;
    if (x > max_val) return max_val;
    return x;
}
