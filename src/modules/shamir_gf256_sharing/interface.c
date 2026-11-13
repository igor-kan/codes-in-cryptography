/**
 * @file interface.c
 * @brief Abstract function prototypes and contracts for Shamir (k, n) Threshold Secret Sharing over GF(256).
 * Module: shamir_gf256_sharing | Algorithm Family: secret_sharing
 */

#ifndef SHAMIR_GF256_SHARING_INTERFACE_H
#define SHAMIR_GF256_SHARING_INTERFACE_H

#include "types.c"

typedef int (*shamir_gf256_sharing_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct shamir_gf256_sharing_vtable {
    int (*init)(shamir_gf256_sharing_state_t* state, const shamir_gf256_sharing_config_t* cfg);
    int (*execute)(shamir_gf256_sharing_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(shamir_gf256_sharing_state_t* state);
    int (*destroy)(shamir_gf256_sharing_state_t* state);
} shamir_gf256_sharing_vtable_t;

#endif /* SHAMIR_GF256_SHARING_INTERFACE_H */
