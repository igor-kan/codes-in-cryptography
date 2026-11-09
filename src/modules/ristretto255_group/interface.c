/**
 * @file interface.c
 * @brief Abstract contracts and prototypes for Prime-Order Group Abstraction over Curve25519.
 * Module: ristretto255_group
 */

#ifndef RISTRETTO255_GROUP_INTERFACE_H
#define RISTRETTO255_GROUP_INTERFACE_H

#include "types.c"

typedef int (*ristretto255_group_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct ristretto255_group_vtable {
    int (*init)(ristretto255_group_state_t* state, const ristretto255_group_config_t* cfg);
    int (*execute)(ristretto255_group_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*destroy)(ristretto255_group_state_t* state);
} ristretto255_group_vtable_t;

#endif /* RISTRETTO255_GROUP_INTERFACE_H */
