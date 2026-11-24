#include "interface.h"

aes_subbytes_sbox_d59_err_t aes_subbytes_sbox_d59_verify_guard(bool cond) {
    if (!cond) {
        return AES_SUBBYTES_SBOX_D59_ERR_INVARIANT;
    }
    return AES_SUBBYTES_SBOX_D59_OK;
}
