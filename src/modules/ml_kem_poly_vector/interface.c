/**
 * @file interface.c
 * @brief Abstract contracts and operational prototypes for ML-KEM (Kyber-768) Vector Polynomial Ring Arithmetic.
 * Module: ml_kem_poly_vector
 */

#ifndef ML_KEM_POLY_VECTOR_INTERFACE_H
#define ML_KEM_POLY_VECTOR_INTERFACE_H

#include "types.c"

typedef int (*ml_kem_poly_vector_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct ml_kem_poly_vector_vtable {
    int (*init)(ml_kem_poly_vector_state_t* state, const ml_kem_poly_vector_config_t* cfg);
    int (*execute)(ml_kem_poly_vector_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(ml_kem_poly_vector_state_t* state);
    int (*destroy)(ml_kem_poly_vector_state_t* state);
} ml_kem_poly_vector_vtable_t;

#endif /* ML_KEM_POLY_VECTOR_INTERFACE_H */
