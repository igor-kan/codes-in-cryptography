/**
 * @file interface.c
 * @brief Abstract contracts and operational prototypes for Constant-Time GF(2^128) Carryless Galois Multiplier.
 * Module: aes_gcm_gfmul
 */

#ifndef AES_GCM_GFMUL_INTERFACE_H
#define AES_GCM_GFMUL_INTERFACE_H

#include "types.c"

typedef int (*aes_gcm_gfmul_transform_fn)(const double* in_data, double* out_data, size_t n);

typedef struct aes_gcm_gfmul_interface {
    int (*init)(aes_gcm_gfmul_state_t* state, const aes_gcm_gfmul_config_t* cfg);
    int (*execute)(aes_gcm_gfmul_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(aes_gcm_gfmul_state_t* state);
    int (*destroy)(aes_gcm_gfmul_state_t* state);
} aes_gcm_gfmul_interface_t;

#endif /* AES_GCM_GFMUL_INTERFACE_H */
