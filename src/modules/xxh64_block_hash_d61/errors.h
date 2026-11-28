#ifndef XXH64_BLOCK_HASH_D61_ERRORS_H
#define XXH64_BLOCK_HASH_D61_ERRORS_H

typedef enum xxh64_block_hash_d61_err {
    XXH64_BLOCK_HASH_D61_OK = 0,
    XXH64_BLOCK_HASH_D61_ERR_NULL = -1,
    XXH64_BLOCK_HASH_D61_ERR_BOUNDS = -2,
    XXH64_BLOCK_HASH_D61_ERR_INVALID = -3,
    XXH64_BLOCK_HASH_D61_ERR_OVERFLOW = -4,
    XXH64_BLOCK_HASH_D61_ERR_INVARIANT = -5
} xxh64_block_hash_d61_err_t;



static inline const char* xxh64_block_hash_d61_err_str(xxh64_block_hash_d61_err_t err) {
    switch (err) {
        case XXH64_BLOCK_HASH_D61_OK: return "ok";
        case XXH64_BLOCK_HASH_D61_ERR_NULL: return "null pointer supplied";
        case XXH64_BLOCK_HASH_D61_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case XXH64_BLOCK_HASH_D61_ERR_INVALID: return "domain precondition violated";
        case XXH64_BLOCK_HASH_D61_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case XXH64_BLOCK_HASH_D61_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* XXH64_BLOCK_HASH_D61_ERRORS_H */
