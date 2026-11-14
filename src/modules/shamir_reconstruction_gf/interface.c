/**
 * @file interface.c
 * @brief Abstract function prototypes and contracts for Lagrange Interpolation Secret Reconstruction GF(256).
 * Module: shamir_reconstruction_gf | Algorithm Family: secret_sharing
 */

#ifndef SHAMIR_RECONSTRUCTION_GF_INTERFACE_H
#define SHAMIR_RECONSTRUCTION_GF_INTERFACE_H

#include "types.c"

typedef int (*shamir_reconstruction_gf_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct shamir_reconstruction_gf_vtable {
    int (*init)(shamir_reconstruction_gf_state_t* state, const shamir_reconstruction_gf_config_t* cfg);
    int (*execute)(shamir_reconstruction_gf_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(shamir_reconstruction_gf_state_t* state);
    int (*destroy)(shamir_reconstruction_gf_state_t* state);
} shamir_reconstruction_gf_vtable_t;

#endif /* SHAMIR_RECONSTRUCTION_GF_INTERFACE_H */
