/**
 * @file interface.c
 * @brief Abstract contracts and prototypes for Parallel Tree-Hashing BLAKE3 Compression Function.
 * Module: blake3_tree_hash
 */

#ifndef BLAKE3_TREE_HASH_INTERFACE_H
#define BLAKE3_TREE_HASH_INTERFACE_H

#include "types.c"

typedef int (*blake3_tree_hash_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct blake3_tree_hash_vtable {
    int (*init)(blake3_tree_hash_state_t* state, const blake3_tree_hash_config_t* cfg);
    int (*execute)(blake3_tree_hash_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*destroy)(blake3_tree_hash_state_t* state);
} blake3_tree_hash_vtable_t;

#endif /* BLAKE3_TREE_HASH_INTERFACE_H */
