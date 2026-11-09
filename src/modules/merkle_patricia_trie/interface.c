/**
 * @file interface.c
 * @brief Abstract contracts and prototypes for Cryptographic Merkle Patricia State Trie Engine.
 * Module: merkle_patricia_trie
 */

#ifndef MERKLE_PATRICIA_TRIE_INTERFACE_H
#define MERKLE_PATRICIA_TRIE_INTERFACE_H

#include "types.c"

typedef int (*merkle_patricia_trie_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct merkle_patricia_trie_vtable {
    int (*init)(merkle_patricia_trie_state_t* state, const merkle_patricia_trie_config_t* cfg);
    int (*execute)(merkle_patricia_trie_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*destroy)(merkle_patricia_trie_state_t* state);
} merkle_patricia_trie_vtable_t;

#endif /* MERKLE_PATRICIA_TRIE_INTERFACE_H */
