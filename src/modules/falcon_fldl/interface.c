/**
 * @file interface.c
 * @brief Abstract contracts and prototypes for Falcon Lattice Fast Fourier Orthogonalization (LDL).
 * Module: falcon_fldl
 */

#ifndef FALCON_FLDL_INTERFACE_H
#define FALCON_FLDL_INTERFACE_H

#include "types.c"

typedef int (*falcon_fldl_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct falcon_fldl_vtable {
    int (*init)(falcon_fldl_state_t* state, const falcon_fldl_config_t* cfg);
    int (*execute)(falcon_fldl_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*destroy)(falcon_fldl_state_t* state);
} falcon_fldl_vtable_t;

#endif /* FALCON_FLDL_INTERFACE_H */
