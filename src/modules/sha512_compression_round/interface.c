/**
 * @file interface.c
 * @brief Abstract function prototypes and contracts for SHA-512 Message Schedule Expansion & Compression.
 * Module: sha512_compression_round | Algorithm Family: sha256
 */

#ifndef SHA512_COMPRESSION_ROUND_INTERFACE_H
#define SHA512_COMPRESSION_ROUND_INTERFACE_H

#include "types.c"

typedef int (*sha512_compression_round_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct sha512_compression_round_vtable {
    int (*init)(sha512_compression_round_state_t* state, const sha512_compression_round_config_t* cfg);
    int (*execute)(sha512_compression_round_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(sha512_compression_round_state_t* state);
    int (*destroy)(sha512_compression_round_state_t* state);
} sha512_compression_round_vtable_t;

#endif /* SHA512_COMPRESSION_ROUND_INTERFACE_H */
