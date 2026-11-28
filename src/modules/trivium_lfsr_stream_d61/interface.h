#ifndef TRIVIUM_LFSR_STREAM_D61_INTERFACE_H
#define TRIVIUM_LFSR_STREAM_D61_INTERFACE_H

#include "types.h"
#include "errors.h"

void trivium_init_d61(trivium_state_d61_t* st, const uint8_t key[10], const uint8_t iv[10]);
uint8_t trivium_bit_d61(trivium_state_d61_t* st);
uint8_t trivium_byte_d61(trivium_state_d61_t* st);
uint64_t trivium_word_d61(trivium_state_d61_t* st);

trivium_lfsr_stream_d61_err_t trivium_lfsr_stream_d61_validate_len(size_t n);
uint64_t trivium_lfsr_stream_d61_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t trivium_lfsr_stream_d61_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
trivium_lfsr_stream_d61_err_t trivium_lfsr_stream_d61_verify_guard(bool cond);

#endif /* TRIVIUM_LFSR_STREAM_D61_INTERFACE_H */
