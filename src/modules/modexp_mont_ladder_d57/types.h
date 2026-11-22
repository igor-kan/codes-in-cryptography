#ifndef MODEXP_MONT_LADDER_D57_TYPES_H
#define MODEXP_MONT_LADDER_D57_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint64_t base;
    uint64_t exp;
    uint64_t mod;
} modexp_req_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} modexp_mont_ladder_d57_meta_t;

#endif /* MODEXP_MONT_LADDER_D57_TYPES_H */
