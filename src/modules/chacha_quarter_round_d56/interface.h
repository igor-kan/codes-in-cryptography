#ifndef CHACHA_QUARTER_ROUND_D56_INTERFACE_H
#define CHACHA_QUARTER_ROUND_D56_INTERFACE_H

#include "types.h"
#include "errors.h"

void chacha_qr(uint32_t *a, uint32_t *b, uint32_t *c, uint32_t *d);
void chacha20_block_words(const uint32_t in[16], uint32_t out[16]);

chacha_quarter_round_d56_err_t chacha_quarter_round_d56_validate_len(size_t n);
uint64_t chacha_quarter_round_d56_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t chacha_quarter_round_d56_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
chacha_quarter_round_d56_err_t chacha_quarter_round_d56_verify_guard(bool cond);

#endif /* CHACHA_QUARTER_ROUND_D56_INTERFACE_H */
