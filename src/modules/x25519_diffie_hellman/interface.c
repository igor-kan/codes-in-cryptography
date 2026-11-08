/**
 * @file interface.c
 * @brief Abstract contracts and operational prototypes for Constant-Time X25519 Montgomery Curve Ladder.
 * Module: x25519_diffie_hellman
 */

#ifndef X25519_DIFFIE_HELLMAN_INTERFACE_H
#define X25519_DIFFIE_HELLMAN_INTERFACE_H

#include "types.c"

typedef int (*x25519_diffie_hellman_transform_fn)(const double* in_data, double* out_data, size_t n);

typedef struct x25519_diffie_hellman_interface {
    int (*init)(x25519_diffie_hellman_state_t* state, const x25519_diffie_hellman_config_t* cfg);
    int (*execute)(x25519_diffie_hellman_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(x25519_diffie_hellman_state_t* state);
    int (*destroy)(x25519_diffie_hellman_state_t* state);
} x25519_diffie_hellman_interface_t;

#endif /* X25519_DIFFIE_HELLMAN_INTERFACE_H */
