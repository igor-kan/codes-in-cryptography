#ifndef ASCON128_AEAD_PERM_INTERFACE_H
#define ASCON128_AEAD_PERM_INTERFACE_H

#include "types.h"
#include "errors.h"

void ascon128_aead_perm_permute(ascon_state_t* s, int rounds);
ascon128_aead_perm_err_t ascon128_aead_perm_encrypt(const uint8_t key[16], const uint8_t nonce[16], const uint8_t* ad, size_t ad_len, const uint8_t* pt, size_t pt_len, uint8_t* ct, uint8_t tag[16]);
ascon128_aead_perm_err_t ascon128_aead_perm_decrypt(const uint8_t key[16], const uint8_t nonce[16], const uint8_t* ad, size_t ad_len, const uint8_t* ct, size_t ct_len, const uint8_t tag[16], uint8_t* pt);
int ascon128_aead_perm_ct_eq16(const uint8_t a[16], const uint8_t b[16]);
ascon128_aead_perm_err_t ascon128_aead_perm_validate(const uint8_t* key, const uint8_t* nonce);
void ascon128_aead_perm_permute_unrolled(ascon_state_t* s);
ascon128_aead_perm_err_t ascon128_aead_perm_batch(const uint8_t key[16], const uint8_t* pt, size_t len);
ascon128_aead_perm_err_t ascon128_aead_perm_verify_roundtrip(const uint8_t key[16], const uint8_t nonce[16], const uint8_t* pt, size_t len);

#endif /* ASCON128_AEAD_PERM_INTERFACE_H */
