/**
 * @file interface.c
 * @brief Abstract contracts and operational prototypes for Memory-Hard Argon2d/Argon2i Block Mixing Permutation.
 * Module: argon2_password_hash
 */

#ifndef ARGON2_PASSWORD_HASH_INTERFACE_H
#define ARGON2_PASSWORD_HASH_INTERFACE_H

#include "types.c"

typedef int (*argon2_password_hash_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct argon2_password_hash_vtable {
    int (*init)(argon2_password_hash_state_t* state, const argon2_password_hash_config_t* cfg);
    int (*execute)(argon2_password_hash_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(argon2_password_hash_state_t* state);
    int (*destroy)(argon2_password_hash_state_t* state);
} argon2_password_hash_vtable_t;

#endif /* ARGON2_PASSWORD_HASH_INTERFACE_H */
