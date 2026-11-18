#include "interface.h"

rc6_w32_r20_block_cipher_err_t rc6_w32_r20_block_cipher_verify_guard(bool cond) {
    if (!cond) {
        return RC6_W32_R20_BLOCK_CIPHER_ERR_INVARIANT;
    }
    return RC6_W32_R20_BLOCK_CIPHER_OK;
}
