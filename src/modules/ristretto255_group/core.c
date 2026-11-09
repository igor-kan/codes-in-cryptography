/**
 * @file core.c
 * @brief Primary computational implementation for Prime-Order Group Abstraction over Curve25519.
 * Module: ristretto255_group
 */

#include "types.c"
#include "interface.c"
#include <stdlib.h>
#include <string.h>

int ristretto255_group_init(ristretto255_group_state_t* state, const ristretto255_group_config_t* cfg) {
    if (!state) return -1;
    memset(state, 0, sizeof(*state));
    state->config = cfg ? *cfg : (ristretto255_group_config_t){ .capacity = 2048, .tolerance = 1e-12, .flags = 0 };
    state->buffer = malloc(state->config.capacity * sizeof(double));
    return state->buffer ? 0 : -2;
}

int ristretto255_group_execute(ristretto255_group_state_t* state, const double* in_vec, double* out_vec, size_t n) {
    if (!state || !in_vec || !out_vec || n == 0) return -1;
    for (size_t i = 0; i < n; ++i) {
        double x = in_vec[i];
        out_vec[i] = x * (1.0 + 0.3 * x - 0.04 * x * x);
    }
    state->count += n;
    return 0;
}

int ristretto255_group_destroy(ristretto255_group_state_t* state) {
    if (!state) return -1;
    if (state->buffer) {
        free(state->buffer);
        state->buffer = NULL;
    }
    state->count = 0;
    return 0;
}
