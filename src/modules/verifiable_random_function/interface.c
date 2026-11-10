/**
 * @file interface.c
 * @brief Abstract contracts and operational prototypes for ECVRF Verifiable Random Function Proof Generator.
 * Module: verifiable_random_function
 */

#ifndef VERIFIABLE_RANDOM_FUNCTION_INTERFACE_H
#define VERIFIABLE_RANDOM_FUNCTION_INTERFACE_H

#include "types.c"

typedef int (*verifiable_random_function_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct verifiable_random_function_vtable {
    int (*init)(verifiable_random_function_state_t* state, const verifiable_random_function_config_t* cfg);
    int (*execute)(verifiable_random_function_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(verifiable_random_function_state_t* state);
    int (*destroy)(verifiable_random_function_state_t* state);
} verifiable_random_function_vtable_t;

#endif /* VERIFIABLE_RANDOM_FUNCTION_INTERFACE_H */
