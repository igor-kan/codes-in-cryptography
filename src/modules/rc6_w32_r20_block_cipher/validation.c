#include "interface.h"

rc6_w32_r20_block_cipher_err_t rc6_w32_r20_block_cipher_validate_len(size_t n) {
    if (n == 0) {
        return RC6_W32_R20_BLOCK_CIPHER_ERR_INVALID;
    }
    return RC6_W32_R20_BLOCK_CIPHER_OK;
}
