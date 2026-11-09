/**
 * @file interface.c
 * @brief Abstract contracts and prototypes for Constant-Time Tonelli-Shanks Quadratic Residue Solver.
 * Module: modular_sqrt_tonelli
 */

#ifndef MODULAR_SQRT_TONELLI_INTERFACE_H
#define MODULAR_SQRT_TONELLI_INTERFACE_H

#include "types.c"

typedef int (*modular_sqrt_tonelli_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct modular_sqrt_tonelli_vtable {
    int (*init)(modular_sqrt_tonelli_state_t* state, const modular_sqrt_tonelli_config_t* cfg);
    int (*execute)(modular_sqrt_tonelli_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*destroy)(modular_sqrt_tonelli_state_t* state);
} modular_sqrt_tonelli_vtable_t;

#endif /* MODULAR_SQRT_TONELLI_INTERFACE_H */
