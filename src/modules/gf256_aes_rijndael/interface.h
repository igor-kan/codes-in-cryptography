#ifndef GF256_AES_RIJNDAEL_INTERFACE_H
#define GF256_AES_RIJNDAEL_INTERFACE_H

#include "types.h"
#include "errors.h"

uint8_t gf256_aes_rijndael_mul(uint8_t a, uint8_t b);
uint8_t gf256_aes_rijndael_inv(uint8_t a);
uint8_t gf256_aes_rijndael_sbox_ct(uint8_t x);
uint8_t gf256_aes_rijndael_invsbox_ct(uint8_t s);
void gf256_aes_rijndael_mix_column(uint8_t c[4]);
void gf256_aes_rijndael_invmix_column(uint8_t c[4]);
gf256_aes_rijndael_err_t gf256_aes_rijndael_validate_nz(uint8_t a);
void gf256_aes_rijndael_mix_state_fast(uint8_t state[16]);
gf256_aes_rijndael_err_t gf256_aes_rijndael_check_all_inverses(void);

#endif /* GF256_AES_RIJNDAEL_INTERFACE_H */
