/**
 * @file interface.c
 * @brief Abstract function prototypes and contracts for Keccak-p[1600, 24] Cryptographic State Permutation.
 * Module: keccak_p1600_perm | Algorithm Family: sponge_state
 */

#ifndef KECCAK_P1600_PERM_INTERFACE_H
#define KECCAK_P1600_PERM_INTERFACE_H

#include "types.c"

typedef int (*keccak_p1600_perm_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct keccak_p1600_perm_vtable {
    int (*init)(keccak_p1600_perm_state_t* state, const keccak_p1600_perm_config_t* cfg);
    int (*execute)(keccak_p1600_perm_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(keccak_p1600_perm_state_t* state);
    int (*destroy)(keccak_p1600_perm_state_t* state);
} keccak_p1600_perm_vtable_t;

#endif /* KECCAK_P1600_PERM_INTERFACE_H */
