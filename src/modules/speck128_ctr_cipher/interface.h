#ifndef SPECK128_CTR_CIPHER_INTERFACE_H
#define SPECK128_CTR_CIPHER_INTERFACE_H

#include "types.h"
#include "errors.h"

void speck128_ctr_cipher_expand(const uint64_t key[2], speck128_rk_t* out);
void speck128_ctr_cipher_enc_block(const speck128_rk_t* rk, const uint64_t pt[2], uint64_t ct[2]);
void speck128_ctr_cipher_dec_block(const speck128_rk_t* rk, const uint64_t ct[2], uint64_t pt[2]);
speck128_ctr_cipher_err_t speck128_ctr_cipher_ctr_crypt(const speck128_rk_t* rk, uint64_t iv_hi, uint64_t ctr, const uint8_t* in, uint8_t* out, size_t len);
speck128_ctr_cipher_err_t speck128_ctr_cipher_validate(const speck128_rk_t* rk);
void speck128_ctr_cipher_enc_ecb_fast(const speck128_rk_t* rk, const uint64_t* pt, uint64_t* ct, size_t nblocks);
speck128_ctr_cipher_err_t speck128_ctr_cipher_batch_check(const speck128_rk_t* rk, size_t n);
speck128_ctr_cipher_err_t speck128_ctr_cipher_verify_kat(void);

#endif /* SPECK128_CTR_CIPHER_INTERFACE_H */
