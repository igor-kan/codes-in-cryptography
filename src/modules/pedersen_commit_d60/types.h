#ifndef PEDERSEN_COMMIT_D60_TYPES_H
#define PEDERSEN_COMMIT_D60_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define PED_P 4294967087ULL
#define PED_Q 2147483543ULL
#define PED_G 4ULL
#define PED_H 9ULL
typedef struct {
    uint64_t value;
    uint64_t blinding;
    uint64_t commit;
} pedersen_open_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} pedersen_commit_d60_meta_t;

#endif /* PEDERSEN_COMMIT_D60_TYPES_H */
