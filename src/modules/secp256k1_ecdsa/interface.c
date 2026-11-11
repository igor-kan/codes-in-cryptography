/**
 * @file interface.c
 * @brief Abstract contracts and operational prototypes for Constant-Time SECP256k1 Jacobian Projective Point Math.
 * Module: secp256k1_ecdsa
 */

#ifndef SECP256K1_ECDSA_INTERFACE_H
#define SECP256K1_ECDSA_INTERFACE_H

#include "types.c"

typedef int (*secp256k1_ecdsa_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct secp256k1_ecdsa_vtable {
    int (*init)(secp256k1_ecdsa_state_t* state, const secp256k1_ecdsa_config_t* cfg);
    int (*execute)(secp256k1_ecdsa_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(secp256k1_ecdsa_state_t* state);
    int (*destroy)(secp256k1_ecdsa_state_t* state);
} secp256k1_ecdsa_vtable_t;

#endif /* SECP256K1_ECDSA_INTERFACE_H */
