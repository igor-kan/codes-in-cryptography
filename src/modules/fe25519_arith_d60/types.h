#ifndef FE25519_ARITH_D60_TYPES_H
#define FE25519_ARITH_D60_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint64_t limb[5];
} fe25519_d60_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} fe25519_arith_d60_meta_t;

#endif /* FE25519_ARITH_D60_TYPES_H */
