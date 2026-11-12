/**
 * @file interface.c
 * @brief Abstract function prototypes and contracts for Duplex Cryptographic Sponge Construction Engine.
 * Module: sponge_duplex_engine | Algorithm Family: sponge_duplex
 */

#ifndef SPONGE_DUPLEX_ENGINE_INTERFACE_H
#define SPONGE_DUPLEX_ENGINE_INTERFACE_H

#include "types.c"

typedef int (*sponge_duplex_engine_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct sponge_duplex_engine_vtable {
    int (*init)(sponge_duplex_engine_state_t* state, const sponge_duplex_engine_config_t* cfg);
    int (*execute)(sponge_duplex_engine_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(sponge_duplex_engine_state_t* state);
    int (*destroy)(sponge_duplex_engine_state_t* state);
} sponge_duplex_engine_vtable_t;

#endif /* SPONGE_DUPLEX_ENGINE_INTERFACE_H */
