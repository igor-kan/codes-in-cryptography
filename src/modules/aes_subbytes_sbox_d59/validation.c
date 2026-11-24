#include "interface.h"

aes_subbytes_sbox_d59_err_t aes_subbytes_sbox_d59_validate_len(size_t n) {
    if (n == 0) {
        return AES_SUBBYTES_SBOX_D59_ERR_INVALID;
    }
    return AES_SUBBYTES_SBOX_D59_OK;
}
