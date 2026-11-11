/**
 * @file interface.c
 * @brief Abstract contracts and operational prototypes for Constant-Time Modular Inverse via Bernstein-Yang Ladder.
 * Module: constant_time_mod_inv
 */

#ifndef CONSTANT_TIME_MOD_INV_INTERFACE_H
#define CONSTANT_TIME_MOD_INV_INTERFACE_H

#include "types.c"

typedef int (*constant_time_mod_inv_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct constant_time_mod_inv_vtable {
    int (*init)(constant_time_mod_inv_state_t* state, const constant_time_mod_inv_config_t* cfg);
    int (*execute)(constant_time_mod_inv_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(constant_time_mod_inv_state_t* state);
    int (*destroy)(constant_time_mod_inv_state_t* state);
} constant_time_mod_inv_vtable_t;

#endif /* CONSTANT_TIME_MOD_INV_INTERFACE_H */
