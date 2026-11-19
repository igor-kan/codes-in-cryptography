#ifndef FEISTEL_LUBY_RACKOFF_C11_TYPES_H
#define FEISTEL_LUBY_RACKOFF_C11_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint32_t rk[4];
} lr_key_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} feistel_luby_rackoff_c11_meta_t;

#endif /* FEISTEL_LUBY_RACKOFF_C11_TYPES_H */
