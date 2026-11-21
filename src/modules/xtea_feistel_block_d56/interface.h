#ifndef XTEA_FEISTEL_BLOCK_D56_INTERFACE_H
#define XTEA_FEISTEL_BLOCK_D56_INTERFACE_H

#include "types.h"
#include "errors.h"

void xtea_encrypt_block(uint32_t v[2], const uint32_t key[4]);
void xtea_decrypt_block(uint32_t v[2], const uint32_t key[4]);

xtea_feistel_block_d56_err_t xtea_feistel_block_d56_validate_len(size_t n);
uint64_t xtea_feistel_block_d56_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t xtea_feistel_block_d56_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
xtea_feistel_block_d56_err_t xtea_feistel_block_d56_verify_guard(bool cond);

#endif /* XTEA_FEISTEL_BLOCK_D56_INTERFACE_H */
