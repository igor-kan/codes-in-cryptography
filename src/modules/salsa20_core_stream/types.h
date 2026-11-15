#ifndef SALSA20_CORE_STREAM_TYPES_H
#define SALSA20_CORE_STREAM_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint32_t state[16];
    uint64_t counter;
} salsa20_matrix_t;

#endif /* SALSA20_CORE_STREAM_TYPES_H */
