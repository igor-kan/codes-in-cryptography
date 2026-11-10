/**
 * @file interface.c
 * @brief Abstract contracts and operational prototypes for SIMD-Accelerated BLAKE2b Cryptographic Hashing Engine.
 * Module: blake2b_simd
 */

#ifndef BLAKE2B_SIMD_INTERFACE_H
#define BLAKE2B_SIMD_INTERFACE_H

#include "types.c"

typedef int (*blake2b_simd_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct blake2b_simd_vtable {
    int (*init)(blake2b_simd_state_t* state, const blake2b_simd_config_t* cfg);
    int (*execute)(blake2b_simd_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(blake2b_simd_state_t* state);
    int (*destroy)(blake2b_simd_state_t* state);
} blake2b_simd_vtable_t;

#endif /* BLAKE2B_SIMD_INTERFACE_H */
