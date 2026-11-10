/**
 * @file interface.c
 * @brief Abstract contracts and operational prototypes for Curve448 (Ed448) Goldilocks Point Arithmetic Ladder.
 * Module: curve448_goldilocks
 */

#ifndef CURVE448_GOLDILOCKS_INTERFACE_H
#define CURVE448_GOLDILOCKS_INTERFACE_H

#include "types.c"

typedef int (*curve448_goldilocks_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct curve448_goldilocks_vtable {
    int (*init)(curve448_goldilocks_state_t* state, const curve448_goldilocks_config_t* cfg);
    int (*execute)(curve448_goldilocks_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(curve448_goldilocks_state_t* state);
    int (*destroy)(curve448_goldilocks_state_t* state);
} curve448_goldilocks_vtable_t;

#endif /* CURVE448_GOLDILOCKS_INTERFACE_H */
