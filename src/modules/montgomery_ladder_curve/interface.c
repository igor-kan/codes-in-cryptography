/**
 * @file interface.c
 * @brief Abstract function prototypes and contracts for Montgomery Ladder Scalar Multiplication on Curves.
 * Module: montgomery_ladder_curve | Algorithm Family: mod_exp
 */

#ifndef MONTGOMERY_LADDER_CURVE_INTERFACE_H
#define MONTGOMERY_LADDER_CURVE_INTERFACE_H

#include "types.c"

typedef int (*montgomery_ladder_curve_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct montgomery_ladder_curve_vtable {
    int (*init)(montgomery_ladder_curve_state_t* state, const montgomery_ladder_curve_config_t* cfg);
    int (*execute)(montgomery_ladder_curve_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(montgomery_ladder_curve_state_t* state);
    int (*destroy)(montgomery_ladder_curve_state_t* state);
} montgomery_ladder_curve_vtable_t;

#endif /* MONTGOMERY_LADDER_CURVE_INTERFACE_H */
