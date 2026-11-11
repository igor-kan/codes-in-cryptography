/**
 * @file interface.c
 * @brief Abstract contracts and operational prototypes for Cryptographic Merkle Sum Tree for Proof of Solvency.
 * Module: merkle_sum_tree
 */

#ifndef MERKLE_SUM_TREE_INTERFACE_H
#define MERKLE_SUM_TREE_INTERFACE_H

#include "types.c"

typedef int (*merkle_sum_tree_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct merkle_sum_tree_vtable {
    int (*init)(merkle_sum_tree_state_t* state, const merkle_sum_tree_config_t* cfg);
    int (*execute)(merkle_sum_tree_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(merkle_sum_tree_state_t* state);
    int (*destroy)(merkle_sum_tree_state_t* state);
} merkle_sum_tree_vtable_t;

#endif /* MERKLE_SUM_TREE_INTERFACE_H */
