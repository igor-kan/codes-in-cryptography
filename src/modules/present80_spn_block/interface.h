#ifndef PRESENT80_SPN_BLOCK_INTERFACE_H
#define PRESENT80_SPN_BLOCK_INTERFACE_H

#include "types.h"
#include "errors.h"

void present80_key_init(present80_key_t* ks, uint64_t key_hi, uint16_t key_lo);
uint64_t present80_encrypt(const present80_key_t* ks, uint64_t state);
uint64_t present80_decrypt(const present80_key_t* ks, uint64_t state);
present80_spn_block_err_t present80_validate(const present80_key_t* ks);
uint64_t present80_fast_cbc_mac(const present80_key_t* ks, const uint64_t* blocks, size_t n);
void present80_parallel_encrypt(const present80_key_t* ks, uint64_t* blocks, size_t n);
present80_spn_block_err_t present80_verify_vector(void);

#endif /* PRESENT80_SPN_BLOCK_INTERFACE_H */
