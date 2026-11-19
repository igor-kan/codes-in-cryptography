#ifndef ELGAMAL_SCHNORR_ZKP_TYPES_H
#define ELGAMAL_SCHNORR_ZKP_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define ZKP_P 4294967087ULL
#define ZKP_Q 2147483543ULL
#define ZKP_G 4ULL
typedef struct {
    uint64_t R;
    uint64_t s;
} schnorr_zkp_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} elgamal_schnorr_zkp_meta_t;

#endif /* ELGAMAL_SCHNORR_ZKP_TYPES_H */
