#ifndef RABIN_MILLER_U64_D59_TYPES_H
#define RABIN_MILLER_U64_D59_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint64_t n;
    int is_prime;
} prime_cert_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} rabin_miller_u64_d59_meta_t;

#endif /* RABIN_MILLER_U64_D59_TYPES_H */
