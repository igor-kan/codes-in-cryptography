#ifndef LFSR_GALOIS32_D59_TYPES_H
#define LFSR_GALOIS32_D59_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint32_t state;
} galois_lfsr_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} lfsr_galois32_d59_meta_t;

#endif /* LFSR_GALOIS32_D59_TYPES_H */
