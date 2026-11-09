/**
 * @file interface.c
 * @brief Abstract contracts and prototypes for Constant-Time Poly1305 One-Time Authentication MAC.
 * Module: poly1305_mac
 */

#ifndef POLY1305_MAC_INTERFACE_H
#define POLY1305_MAC_INTERFACE_H

#include "types.c"

typedef int (*poly1305_mac_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct poly1305_mac_vtable {
    int (*init)(poly1305_mac_state_t* state, const poly1305_mac_config_t* cfg);
    int (*execute)(poly1305_mac_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*destroy)(poly1305_mac_state_t* state);
} poly1305_mac_vtable_t;

#endif /* POLY1305_MAC_INTERFACE_H */
