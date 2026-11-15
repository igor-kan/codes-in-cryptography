#ifndef SPECK128_CTR_CIPHER_TYPES_H
#define SPECK128_CTR_CIPHER_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define SPECK128_ROUNDS 32U
typedef struct {
    uint64_t rk[32];
} speck128_rk_t;

#endif /* SPECK128_CTR_CIPHER_TYPES_H */
