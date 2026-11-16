#ifndef SHA1_RFC3174_COMPAT_TYPES_H
#define SHA1_RFC3174_COMPAT_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint32_t state[5];
    uint64_t count;
    uint8_t buf[64];
} sha1_ctx_t;

#endif /* SHA1_RFC3174_COMPAT_TYPES_H */
