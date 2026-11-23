#ifndef PRESENT80_SBOX_D58_TYPES_H
#define PRESENT80_SBOX_D58_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint64_t state;
    int rounds;
} spn_blk_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} present80_sbox_d58_meta_t;

#endif /* PRESENT80_SBOX_D58_TYPES_H */
