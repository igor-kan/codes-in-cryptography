#ifndef CHACHA20_QUARTER_D60_INTERFACE_H
#define CHACHA20_QUARTER_D60_INTERFACE_H

#include "types.h"
#include "errors.h"

void chacha20_qround_d60(uint32_t* x, int a, int b, int c, int d);
void chacha20_block_words_d60(const uint32_t key[8], uint32_t ctr, const uint32_t nonce[3], uint32_t out[16]);

chacha20_quarter_d60_err_t chacha20_quarter_d60_validate_len(size_t n);
uint64_t chacha20_quarter_d60_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t chacha20_quarter_d60_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
chacha20_quarter_d60_err_t chacha20_quarter_d60_verify_guard(bool cond);

#endif /* CHACHA20_QUARTER_D60_INTERFACE_H */
