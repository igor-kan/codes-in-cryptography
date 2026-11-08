/**
 * @file interface.c
 * @brief Abstract contracts and operational prototypes for ML-DSA (Dilithium) NTT Polynomial Multiplier.
 * Module: dilithium_poly_mul
 */

#ifndef DILITHIUM_POLY_MUL_INTERFACE_H
#define DILITHIUM_POLY_MUL_INTERFACE_H

#include "types.c"

typedef int (*dilithium_poly_mul_transform_fn)(const double* in_data, double* out_data, size_t n);

typedef struct dilithium_poly_mul_interface {
    int (*init)(dilithium_poly_mul_state_t* state, const dilithium_poly_mul_config_t* cfg);
    int (*execute)(dilithium_poly_mul_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(dilithium_poly_mul_state_t* state);
    int (*destroy)(dilithium_poly_mul_state_t* state);
} dilithium_poly_mul_interface_t;

#endif /* DILITHIUM_POLY_MUL_INTERFACE_H */
