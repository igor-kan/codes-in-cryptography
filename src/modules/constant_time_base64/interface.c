/**
 * @file interface.c
 * @brief Abstract contracts and prototypes for Side-Channel Immune Constant-Time Base64 Engine.
 * Module: constant_time_base64
 */

#ifndef CONSTANT_TIME_BASE64_INTERFACE_H
#define CONSTANT_TIME_BASE64_INTERFACE_H

#include "types.c"

typedef int (*constant_time_base64_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct constant_time_base64_vtable {
    int (*init)(constant_time_base64_state_t* state, const constant_time_base64_config_t* cfg);
    int (*execute)(constant_time_base64_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*destroy)(constant_time_base64_state_t* state);
} constant_time_base64_vtable_t;

#endif /* CONSTANT_TIME_BASE64_INTERFACE_H */
