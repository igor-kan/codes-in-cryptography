/**
 * @file interface.c
 * @brief Abstract function prototypes and contracts for Keccak-f[1600] 5x5 Lane Parity Theta Transformation.
 * Module: keccak_f1600_theta | Algorithm Family: sponge_state
 */

#ifndef KECCAK_F1600_THETA_INTERFACE_H
#define KECCAK_F1600_THETA_INTERFACE_H

#include "types.c"

typedef int (*keccak_f1600_theta_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct keccak_f1600_theta_vtable {
    int (*init)(keccak_f1600_theta_state_t* state, const keccak_f1600_theta_config_t* cfg);
    int (*execute)(keccak_f1600_theta_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(keccak_f1600_theta_state_t* state);
    int (*destroy)(keccak_f1600_theta_state_t* state);
} keccak_f1600_theta_vtable_t;

#endif /* KECCAK_F1600_THETA_INTERFACE_H */
