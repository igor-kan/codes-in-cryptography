#ifndef SIMON64_128_FEISTEL_INTERFACE_H
#define SIMON64_128_FEISTEL_INTERFACE_H

#include "types.h"
#include "errors.h"

void simon64_key_init(simon64_key_t* ks, const uint32_t key_words[4]);
void simon64_encrypt_block(const simon64_key_t* ks, const uint32_t pt[2], uint32_t ct[2]);
void simon64_decrypt_block(const simon64_key_t* ks, const uint32_t ct[2], uint32_t pt[2]);
simon64_128_feistel_err_t simon64_validate_ptr(const void* p);
void simon64_fast_ecb_xor(const simon64_key_t* ks, uint64_t* blocks, size_t n);
void simon64_parallel_ctr(const simon64_key_t* ks, uint64_t nonce, uint64_t* buf, size_t n);
simon64_128_feistel_err_t simon64_verify_roundtrip(const uint32_t key[4], const uint32_t pt[2]);

#endif /* SIMON64_128_FEISTEL_INTERFACE_H */
