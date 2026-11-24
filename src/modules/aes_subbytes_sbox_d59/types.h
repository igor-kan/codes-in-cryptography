#ifndef AES_SUBBYTES_SBOX_D59_TYPES_H
#define AES_SUBBYTES_SBOX_D59_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint8_t sub_byte;
    uint8_t inv_byte;
} sbox_pair_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} aes_subbytes_sbox_d59_meta_t;

#endif /* AES_SUBBYTES_SBOX_D59_TYPES_H */
