/**
 * @file interface.c
 * @brief Abstract contracts and prototypes for Zero-Knowledge Friendly Algebraic Poseidon Hash.
 * Module: poseidon_hash
 */

#ifndef POSEIDON_HASH_INTERFACE_H
#define POSEIDON_HASH_INTERFACE_H

#include "types.c"

typedef int (*poseidon_hash_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct poseidon_hash_vtable {
    int (*init)(poseidon_hash_state_t* state, const poseidon_hash_config_t* cfg);
    int (*execute)(poseidon_hash_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*destroy)(poseidon_hash_state_t* state);
} poseidon_hash_vtable_t;

#endif /* POSEIDON_HASH_INTERFACE_H */
