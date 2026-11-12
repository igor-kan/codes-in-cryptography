/**
 * @file interface.c
 * @brief Abstract function prototypes and contracts for Luby-Rackoff 4-Round Balanced Feistel Block Cipher.
 * Module: feistel_cipher_round | Algorithm Family: feistel
 */

#ifndef FEISTEL_CIPHER_ROUND_INTERFACE_H
#define FEISTEL_CIPHER_ROUND_INTERFACE_H

#include "types.c"

typedef int (*feistel_cipher_round_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct feistel_cipher_round_vtable {
    int (*init)(feistel_cipher_round_state_t* state, const feistel_cipher_round_config_t* cfg);
    int (*execute)(feistel_cipher_round_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(feistel_cipher_round_state_t* state);
    int (*destroy)(feistel_cipher_round_state_t* state);
} feistel_cipher_round_vtable_t;

#endif /* FEISTEL_CIPHER_ROUND_INTERFACE_H */
