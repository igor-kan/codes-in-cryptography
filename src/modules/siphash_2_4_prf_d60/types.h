#ifndef SIPHASH_2_4_PRF_D60_TYPES_H
#define SIPHASH_2_4_PRF_D60_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint64_t k0;
    uint64_t k1;
} sipkey_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} siphash_2_4_prf_d60_meta_t;

#endif /* SIPHASH_2_4_PRF_D60_TYPES_H */
