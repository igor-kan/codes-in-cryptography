/**
 * @file interface.c
 * @brief Abstract function prototypes and contracts for Constant-Time Poly1305 Clamping and Modular MAC.
 * Module: poly1305_clamp_ladder | Algorithm Family: poly_mac
 */

#ifndef POLY1305_CLAMP_LADDER_INTERFACE_H
#define POLY1305_CLAMP_LADDER_INTERFACE_H

#include "types.c"

typedef int (*poly1305_clamp_ladder_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct poly1305_clamp_ladder_vtable {
    int (*init)(poly1305_clamp_ladder_state_t* state, const poly1305_clamp_ladder_config_t* cfg);
    int (*execute)(poly1305_clamp_ladder_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(poly1305_clamp_ladder_state_t* state);
    int (*destroy)(poly1305_clamp_ladder_state_t* state);
} poly1305_clamp_ladder_vtable_t;

#endif /* POLY1305_CLAMP_LADDER_INTERFACE_H */
