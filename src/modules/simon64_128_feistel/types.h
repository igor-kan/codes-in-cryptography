#ifndef SIMON64_128_FEISTEL_TYPES_H
#define SIMON64_128_FEISTEL_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint32_t rk[44];
} simon64_key_t;

#endif /* SIMON64_128_FEISTEL_TYPES_H */
