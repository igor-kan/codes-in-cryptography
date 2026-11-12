/**
 * @file interface.c
 * @brief Abstract function prototypes and contracts for BLAKE2s Quarter-Round G Mixing Function Engine.
 * Module: blake2s_compression | Algorithm Family: blake_round
 */

#ifndef BLAKE2S_COMPRESSION_INTERFACE_H
#define BLAKE2S_COMPRESSION_INTERFACE_H

#include "types.c"

typedef int (*blake2s_compression_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct blake2s_compression_vtable {
    int (*init)(blake2s_compression_state_t* state, const blake2s_compression_config_t* cfg);
    int (*execute)(blake2s_compression_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(blake2s_compression_state_t* state);
    int (*destroy)(blake2s_compression_state_t* state);
} blake2s_compression_vtable_t;

#endif /* BLAKE2S_COMPRESSION_INTERFACE_H */
