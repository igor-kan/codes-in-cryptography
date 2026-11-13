/**
 * @file interface.c
 * @brief Abstract function prototypes and contracts for Constant-Time Square-and-Multiply Modular Exponentiation.
 * Module: modular_exponentiation_ladder | Algorithm Family: mod_exp
 */

#ifndef MODULAR_EXPONENTIATION_LADDER_INTERFACE_H
#define MODULAR_EXPONENTIATION_LADDER_INTERFACE_H

#include "types.c"

typedef int (*modular_exponentiation_ladder_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct modular_exponentiation_ladder_vtable {
    int (*init)(modular_exponentiation_ladder_state_t* state, const modular_exponentiation_ladder_config_t* cfg);
    int (*execute)(modular_exponentiation_ladder_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(modular_exponentiation_ladder_state_t* state);
    int (*destroy)(modular_exponentiation_ladder_state_t* state);
} modular_exponentiation_ladder_vtable_t;

#endif /* MODULAR_EXPONENTIATION_LADDER_INTERFACE_H */
