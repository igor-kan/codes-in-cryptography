#ifndef FROST_THRESHOLD_COMBINE_TYPES_H
#define FROST_THRESHOLD_COMBINE_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define FROST_P 4294967087ULL
#define FROST_Q 2147483543ULL
#define FROST_G 4ULL

typedef struct {
    uint64_t id;
    uint64_t share;
    uint64_t nonce_share;
} frost_signer_t;

#endif /* FROST_THRESHOLD_COMBINE_TYPES_H */
