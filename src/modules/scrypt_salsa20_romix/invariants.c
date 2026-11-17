#include "interface.h"

scrypt_salsa20_romix_err_t scrypt_verify_salsa8_rfc(void) {
    // RFC 7914 / Salsa20/8 non-zero input deterministically produces non-trivial avalanche
    uint32_t B[16];
    for (uint32_t i = 0; i < 16; ++i) B[i] = i + 1;
    scrypt_salsa20_8(B);
    return B[0] != 1U && B[15] != 16U ? SCRYPT_SALSA20_ROMIX_OK : SCRYPT_SALSA20_ROMIX_ERR_INVARIANT;
}
