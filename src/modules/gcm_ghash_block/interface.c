/**
 * @file interface.c
 * @brief Abstract function prototypes and contracts for Galois/Counter Mode (GCM) GHASH Block Field Multiply.
 * Module: gcm_ghash_block | Algorithm Family: ghash
 */

#ifndef GCM_GHASH_BLOCK_INTERFACE_H
#define GCM_GHASH_BLOCK_INTERFACE_H

#include "types.c"

typedef int (*gcm_ghash_block_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct gcm_ghash_block_vtable {
    int (*init)(gcm_ghash_block_state_t* state, const gcm_ghash_block_config_t* cfg);
    int (*execute)(gcm_ghash_block_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(gcm_ghash_block_state_t* state);
    int (*destroy)(gcm_ghash_block_state_t* state);
} gcm_ghash_block_vtable_t;

#endif /* GCM_GHASH_BLOCK_INTERFACE_H */
