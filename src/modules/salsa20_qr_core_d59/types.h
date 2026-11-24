#ifndef SALSA20_QR_CORE_D59_TYPES_H
#define SALSA20_QR_CORE_D59_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint32_t words[16];
} salsa_block_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} salsa20_qr_core_d59_meta_t;

#endif /* SALSA20_QR_CORE_D59_TYPES_H */
