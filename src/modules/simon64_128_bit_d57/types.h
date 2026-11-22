#ifndef SIMON64_128_BIT_D57_TYPES_H
#define SIMON64_128_BIT_D57_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint32_t rk[44];
} simon64_key_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} simon64_128_bit_d57_meta_t;

#endif /* SIMON64_128_BIT_D57_TYPES_H */
