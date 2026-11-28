#ifndef PAILLIER_ADDITIVE_HE_D61_TYPES_H
#define PAILLIER_ADDITIVE_HE_D61_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define PAIL_P 1019ULL
#define PAIL_Q 1031ULL
#define PAIL_N (PAIL_P * PAIL_Q)
typedef struct {
    uint64_t modulus;
    uint64_t modulus_sq;
    uint64_t lambda;
    uint64_t mu;
} paillier_key_d61_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} paillier_additive_he_d61_meta_t;

#endif /* PAILLIER_ADDITIVE_HE_D61_TYPES_H */
