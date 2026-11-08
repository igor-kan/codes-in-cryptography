/**
 * @file interface.c
 * @brief Abstract contracts and operational prototypes for Feldman Verifiable Secret Sharing Engine.
 * Module: verifiable_secret_sharing
 */

#ifndef VERIFIABLE_SECRET_SHARING_INTERFACE_H
#define VERIFIABLE_SECRET_SHARING_INTERFACE_H

#include "types.c"

typedef int (*verifiable_secret_sharing_transform_fn)(const double* in_data, double* out_data, size_t n);

typedef struct verifiable_secret_sharing_interface {
    int (*init)(verifiable_secret_sharing_state_t* state, const verifiable_secret_sharing_config_t* cfg);
    int (*execute)(verifiable_secret_sharing_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(verifiable_secret_sharing_state_t* state);
    int (*destroy)(verifiable_secret_sharing_state_t* state);
} verifiable_secret_sharing_interface_t;

#endif /* VERIFIABLE_SECRET_SHARING_INTERFACE_H */
