#ifndef CHACHA20_QUARTER_D60_TYPES_H
#define CHACHA20_QUARTER_D60_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint32_t state[16];
} chacha20_block_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} chacha20_quarter_d60_meta_t;

#endif /* CHACHA20_QUARTER_D60_TYPES_H */
