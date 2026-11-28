#ifndef XXH64_BLOCK_HASH_D61_INTERFACE_H
#define XXH64_BLOCK_HASH_D61_INTERFACE_H

#include "types.h"
#include "errors.h"

uint64_t xxh64_d61(const uint8_t* data, size_t len, uint64_t seed);

xxh64_block_hash_d61_err_t xxh64_block_hash_d61_validate_len(size_t n);
uint64_t xxh64_block_hash_d61_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t xxh64_block_hash_d61_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
xxh64_block_hash_d61_err_t xxh64_block_hash_d61_verify_guard(bool cond);

#endif /* XXH64_BLOCK_HASH_D61_INTERFACE_H */
