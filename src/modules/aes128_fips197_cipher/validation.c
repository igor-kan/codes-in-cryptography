#include "interface.h"

aes128_fips197_cipher_err_t aes128_validate_ctx(const aes128_ctx_t* ctx) {
    if (!ctx) return AES128_FIPS197_CIPHER_ERR_NULL;
    return AES128_FIPS197_CIPHER_OK;
}
