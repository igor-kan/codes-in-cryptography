/**
 * @file boundary.c
 * @brief Boundary validation and exceptional input guarding for ML-KEM Pseudo-Random Function and Hash Wrappers (SHAKE).
 * Module: kyber_symmetric_crypto
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool kyber_symmetric_crypto_is_valid_float(double x) {
    return isfinite(x);
}

static inline double kyber_symmetric_crypto_clamp_input(double x, double min_val, double max_val) {
    if (!isfinite(x)) return 0.0;
    if (x < min_val) return min_val;
    if (x > max_val) return max_val;
    return x;
}
