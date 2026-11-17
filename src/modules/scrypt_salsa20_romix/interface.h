#ifndef SCRYPT_SALSA20_ROMIX_INTERFACE_H
#define SCRYPT_SALSA20_ROMIX_INTERFACE_H

#include "types.h"
#include "errors.h"

void scrypt_salsa20_8(uint32_t B[16]);
void scrypt_blockmix(const uint32_t* B, uint32_t* Y, size_t r);
scrypt_salsa20_romix_err_t scrypt_romix(uint32_t* B, size_t r, size_t N, uint32_t* V);
scrypt_salsa20_romix_err_t scrypt_validate_n(size_t N, size_t r);
void scrypt_fast_xor32(uint32_t* dst, const uint32_t* a, const uint32_t* b, size_t words);
void scrypt_parallel_romix(uint32_t* B1, uint32_t* V1, uint32_t* B2, uint32_t* V2, size_t r, size_t N);
scrypt_salsa20_romix_err_t scrypt_verify_salsa8_rfc(void);

#endif /* SCRYPT_SALSA20_ROMIX_INTERFACE_H */
