/**
 * @file interface.c
 * @brief Abstract function prototypes and contracts for ChaCha20 Quarter-Round Column and Diagonal State Mixing.
 * Module: chacha20_block_qr | Algorithm Family: cipher_core
 */

#ifndef CHACHA20_BLOCK_QR_INTERFACE_H
#define CHACHA20_BLOCK_QR_INTERFACE_H

#include "types.c"

typedef int (*chacha20_block_qr_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct chacha20_block_qr_vtable {
    int (*init)(chacha20_block_qr_state_t* state, const chacha20_block_qr_config_t* cfg);
    int (*execute)(chacha20_block_qr_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(chacha20_block_qr_state_t* state);
    int (*destroy)(chacha20_block_qr_state_t* state);
} chacha20_block_qr_vtable_t;

#endif /* CHACHA20_BLOCK_QR_INTERFACE_H */
