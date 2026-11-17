#ifndef RFC3394_KEYWRAP_CIPHER_INTERFACE_H
#define RFC3394_KEYWRAP_CIPHER_INTERFACE_H

#include "types.h"
#include "errors.h"

rfc3394_keywrap_cipher_err_t rfc3394_wrap(kek128_t kek, const uint64_t* pt_blocks, size_t n_blocks, uint64_t* out_ct);
rfc3394_keywrap_cipher_err_t rfc3394_unwrap(kek128_t kek, const uint64_t* ct_blocks, size_t n_blocks, uint64_t* out_pt);
rfc3394_keywrap_cipher_err_t rfc3394_validate_n(size_t n_blocks);
void fast_speck128_pair(kek128_t kek, uint64_t* a, uint64_t* b, bool invert);
void rfc3394_parallel_wrap(kek128_t kek, const uint64_t* cek_a, const uint64_t* cek_b, size_t n, uint64_t* out_a, uint64_t* out_b);
rfc3394_keywrap_cipher_err_t rfc3394_verify_tamper_detection(kek128_t kek, const uint64_t* pt, size_t n);

#endif /* RFC3394_KEYWRAP_CIPHER_INTERFACE_H */
