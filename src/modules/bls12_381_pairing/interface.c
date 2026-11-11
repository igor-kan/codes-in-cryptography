/**
 * @file interface.c
 * @brief Abstract contracts and operational prototypes for BLS12-381 Ate Pairing and Miller Loop Accumulator.
 * Module: bls12_381_pairing
 */

#ifndef BLS12_381_PAIRING_INTERFACE_H
#define BLS12_381_PAIRING_INTERFACE_H

#include "types.c"

typedef int (*bls12_381_pairing_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct bls12_381_pairing_vtable {
    int (*init)(bls12_381_pairing_state_t* state, const bls12_381_pairing_config_t* cfg);
    int (*execute)(bls12_381_pairing_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(bls12_381_pairing_state_t* state);
    int (*destroy)(bls12_381_pairing_state_t* state);
} bls12_381_pairing_vtable_t;

#endif /* BLS12_381_PAIRING_INTERFACE_H */
