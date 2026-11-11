/**
 * @file interface.c
 * @brief Abstract contracts and operational prototypes for Zero-Knowledge Inner Product Argument Verification.
 * Module: bulletproofs_inner_product
 */

#ifndef BULLETPROOFS_INNER_PRODUCT_INTERFACE_H
#define BULLETPROOFS_INNER_PRODUCT_INTERFACE_H

#include "types.c"

typedef int (*bulletproofs_inner_product_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct bulletproofs_inner_product_vtable {
    int (*init)(bulletproofs_inner_product_state_t* state, const bulletproofs_inner_product_config_t* cfg);
    int (*execute)(bulletproofs_inner_product_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(bulletproofs_inner_product_state_t* state);
    int (*destroy)(bulletproofs_inner_product_state_t* state);
} bulletproofs_inner_product_vtable_t;

#endif /* BULLETPROOFS_INNER_PRODUCT_INTERFACE_H */
