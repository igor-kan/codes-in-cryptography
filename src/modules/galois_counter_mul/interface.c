/**
 * @file interface.c
 * @brief Abstract function prototypes and contracts for Constant-Time GHASH 128-Bit Carryless Field Multiply.
 * Module: galois_counter_mul | Algorithm Family: ghash
 */

#ifndef GALOIS_COUNTER_MUL_INTERFACE_H
#define GALOIS_COUNTER_MUL_INTERFACE_H

#include "types.c"

typedef int (*galois_counter_mul_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct galois_counter_mul_vtable {
    int (*init)(galois_counter_mul_state_t* state, const galois_counter_mul_config_t* cfg);
    int (*execute)(galois_counter_mul_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(galois_counter_mul_state_t* state);
    int (*destroy)(galois_counter_mul_state_t* state);
} galois_counter_mul_vtable_t;

#endif /* GALOIS_COUNTER_MUL_INTERFACE_H */
