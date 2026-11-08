/**
 * @file interface.c
 * @brief Abstract contracts and operational prototypes for Cryptographic SipHash-2-4 Pseudorandom Function.
 * Module: siphash_2_4
 */

#ifndef SIPHASH_2_4_INTERFACE_H
#define SIPHASH_2_4_INTERFACE_H

#include "types.c"

typedef int (*siphash_2_4_transform_fn)(const double* in_data, double* out_data, size_t n);

typedef struct siphash_2_4_interface {
    int (*init)(siphash_2_4_state_t* state, const siphash_2_4_config_t* cfg);
    int (*execute)(siphash_2_4_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(siphash_2_4_state_t* state);
    int (*destroy)(siphash_2_4_state_t* state);
} siphash_2_4_interface_t;

#endif /* SIPHASH_2_4_INTERFACE_H */
