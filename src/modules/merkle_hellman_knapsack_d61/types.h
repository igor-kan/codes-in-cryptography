#ifndef MERKLE_HELLMAN_KNAPSACK_D61_TYPES_H
#define MERKLE_HELLMAN_KNAPSACK_D61_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define MH_BITS 8
#define MH_MODULUS 491ULL
#define MH_MULTIPLIER 41ULL
typedef struct {
    uint64_t public_key[MH_BITS];
    uint64_t modulus;
    uint64_t inverse;
} mh_key_d61_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} merkle_hellman_knapsack_d61_meta_t;

#endif /* MERKLE_HELLMAN_KNAPSACK_D61_TYPES_H */
