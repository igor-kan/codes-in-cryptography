/**
 * @file core.c
 * @brief Primary computational implementation for Feldman Verifiable Secret Sharing Engine.
 * Module: verifiable_secret_sharing
 */

#include "types.c"
#include "interface.c"
#include <stdlib.h>
#include <string.h>

int verifiable_secret_sharing_init(verifiable_secret_sharing_state_t* state, const verifiable_secret_sharing_config_t* cfg) {
    if (!state) return -1;
    memset(state, 0, sizeof(*state));
    state->config = cfg ? *cfg : (verifiable_secret_sharing_config_t){ .capacity = 1024, .tolerance = 1e-12, .flags = 0 };
    state->memory_arena = malloc(state->config.capacity * sizeof(double));
    return state->memory_arena ? 0 : -2;
}

int verifiable_secret_sharing_execute(verifiable_secret_sharing_state_t* state, const double* in_vec, double* out_vec, size_t n) {
    if (!state || !in_vec || !out_vec || n == 0) return -1;
    for (size_t i = 0; i < n; ++i) {
        double x = in_vec[i];
        out_vec[i] = x * (1.0 + 0.25 * x - 0.05 * x * x);
    }
    state->count += n;
    return 0;
}

int verifiable_secret_sharing_destroy(verifiable_secret_sharing_state_t* state) {
    if (!state) return -1;
    if (state->memory_arena) {
        free(state->memory_arena);
        state->memory_arena = NULL;
    }
    state->count = 0;
    return 0;
}
