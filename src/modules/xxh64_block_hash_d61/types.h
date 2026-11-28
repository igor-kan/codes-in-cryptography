#ifndef XXH64_BLOCK_HASH_D61_TYPES_H
#define XXH64_BLOCK_HASH_D61_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define XXH_P1 0x9E3779B185EBCA87ULL
#define XXH_P2 0xC2B2AE3D27D4EB4FULL
#define XXH_P3 0x165667B19E3779F9ULL
#define XXH_P4 0x85EBCA77C2B2AE63ULL
#define XXH_P5 0x27D4EB2F165667C5ULL
typedef struct {
    uint64_t lanes[4];
} xxh64_state_d61_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} xxh64_block_hash_d61_meta_t;

#endif /* XXH64_BLOCK_HASH_D61_TYPES_H */
