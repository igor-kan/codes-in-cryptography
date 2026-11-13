/**
 * @file interface.c
 * @brief Abstract function prototypes and contracts for SHA-256 Schedule Expansion and Compression Round.
 * Module: sha256_compression_round | Algorithm Family: sha256
 */

#ifndef SHA256_COMPRESSION_ROUND_INTERFACE_H
#define SHA256_COMPRESSION_ROUND_INTERFACE_H

#include "types.c"

typedef int (*sha256_compression_round_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct sha256_compression_round_vtable {
    int (*init)(sha256_compression_round_state_t* state, const sha256_compression_round_config_t* cfg);
    int (*execute)(sha256_compression_round_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(sha256_compression_round_state_t* state);
    int (*destroy)(sha256_compression_round_state_t* state);
} sha256_compression_round_vtable_t;

#endif /* SHA256_COMPRESSION_ROUND_INTERFACE_H */
