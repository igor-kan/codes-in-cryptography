/**
 * @file interface.c
 * @brief Abstract function prototypes and contracts for ChaCha20-Poly1305 Authenticated Encryption (AEAD).
 * Module: chacha20_poly1305_aead | Algorithm Family: cipher_core
 */

#ifndef CHACHA20_POLY1305_AEAD_INTERFACE_H
#define CHACHA20_POLY1305_AEAD_INTERFACE_H

#include "types.c"

typedef int (*chacha20_poly1305_aead_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct chacha20_poly1305_aead_vtable {
    int (*init)(chacha20_poly1305_aead_state_t* state, const chacha20_poly1305_aead_config_t* cfg);
    int (*execute)(chacha20_poly1305_aead_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(chacha20_poly1305_aead_state_t* state);
    int (*destroy)(chacha20_poly1305_aead_state_t* state);
} chacha20_poly1305_aead_vtable_t;

#endif /* CHACHA20_POLY1305_AEAD_INTERFACE_H */
