/**
 * @file interface.c
 * @brief Abstract contracts and operational prototypes for Homomorphic Pedersen Vector Commitments over Curves.
 * Module: pedersen_commitments
 */

#ifndef PEDERSEN_COMMITMENTS_INTERFACE_H
#define PEDERSEN_COMMITMENTS_INTERFACE_H

#include "types.c"

typedef int (*pedersen_commitments_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct pedersen_commitments_vtable {
    int (*init)(pedersen_commitments_state_t* state, const pedersen_commitments_config_t* cfg);
    int (*execute)(pedersen_commitments_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(pedersen_commitments_state_t* state);
    int (*destroy)(pedersen_commitments_state_t* state);
} pedersen_commitments_vtable_t;

#endif /* PEDERSEN_COMMITMENTS_INTERFACE_H */
