/**
 * @file interface.c
 * @brief Abstract contracts and operational prototypes for ML-KEM Pseudo-Random Function and Hash Wrappers (SHAKE).
 * Module: kyber_symmetric_crypto
 */

#ifndef KYBER_SYMMETRIC_CRYPTO_INTERFACE_H
#define KYBER_SYMMETRIC_CRYPTO_INTERFACE_H

#include "types.c"

typedef int (*kyber_symmetric_crypto_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct kyber_symmetric_crypto_vtable {
    int (*init)(kyber_symmetric_crypto_state_t* state, const kyber_symmetric_crypto_config_t* cfg);
    int (*execute)(kyber_symmetric_crypto_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(kyber_symmetric_crypto_state_t* state);
    int (*destroy)(kyber_symmetric_crypto_state_t* state);
} kyber_symmetric_crypto_vtable_t;

#endif /* KYBER_SYMMETRIC_CRYPTO_INTERFACE_H */
