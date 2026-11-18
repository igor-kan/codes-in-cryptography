#ifndef ELGAMAL_MULTIPLICATIVE_HOM_TYPES_H
#define ELGAMAL_MULTIPLICATIVE_HOM_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define ELG_P 4294967087ULL
#define ELG_G 4ULL
typedef struct {
    uint64_t c1;
    uint64_t c2;
} elg_cipher_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} elgamal_multiplicative_hom_meta_t;

#endif /* ELGAMAL_MULTIPLICATIVE_HOM_TYPES_H */
