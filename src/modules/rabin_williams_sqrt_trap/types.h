#ifndef RABIN_WILLIAMS_SQRT_TRAP_TYPES_H
#define RABIN_WILLIAMS_SQRT_TRAP_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint64_t p;
    uint64_t q;
    uint64_t n;
} rabin_key_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} rabin_williams_sqrt_trap_meta_t;

#endif /* RABIN_WILLIAMS_SQRT_TRAP_TYPES_H */
