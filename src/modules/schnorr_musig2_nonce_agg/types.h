#ifndef SCHNORR_MUSIG2_NONCE_AGG_TYPES_H
#define SCHNORR_MUSIG2_NONCE_AGG_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define MUSIG_P 4294967087ULL
#define MUSIG_Q 2147483543ULL
#define MUSIG_G 4ULL
typedef struct {
    uint64_t r1;
    uint64_t r2;
    uint64_t R1;
    uint64_t R2;
} musig_nonce_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} schnorr_musig2_nonce_agg_meta_t;

#endif /* SCHNORR_MUSIG2_NONCE_AGG_TYPES_H */
