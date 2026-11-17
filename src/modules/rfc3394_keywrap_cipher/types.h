#ifndef RFC3394_KEYWRAP_CIPHER_TYPES_H
#define RFC3394_KEYWRAP_CIPHER_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define RFC3394_DEFAULT_IV 0xA6A6A6A6A6A6A6A6ULL
typedef struct {
    uint64_t k0;
    uint64_t k1;
} kek128_t;

#endif /* RFC3394_KEYWRAP_CIPHER_TYPES_H */
