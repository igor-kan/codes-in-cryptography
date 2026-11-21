#ifndef CHACHA_QUARTER_ROUND_D56_TYPES_H
#define CHACHA_QUARTER_ROUND_D56_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint32_t s[16];
} chacha_state_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} chacha_quarter_round_d56_meta_t;

#endif /* CHACHA_QUARTER_ROUND_D56_TYPES_H */
