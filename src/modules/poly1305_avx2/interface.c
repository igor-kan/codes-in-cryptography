/**
 * @file interface.c
 * @brief Abstract contracts and operational prototypes for AVX2-Accelerated Poly1305 Message Authentication Code.
 * Module: poly1305_avx2
 */

#ifndef POLY1305_AVX2_INTERFACE_H
#define POLY1305_AVX2_INTERFACE_H

#include "types.c"

typedef int (*poly1305_avx2_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct poly1305_avx2_vtable {
    int (*init)(poly1305_avx2_state_t* state, const poly1305_avx2_config_t* cfg);
    int (*execute)(poly1305_avx2_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(poly1305_avx2_state_t* state);
    int (*destroy)(poly1305_avx2_state_t* state);
} poly1305_avx2_vtable_t;

#endif /* POLY1305_AVX2_INTERFACE_H */
