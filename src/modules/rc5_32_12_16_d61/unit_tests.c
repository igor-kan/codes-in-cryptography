#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(rc5_32_12_16_d61_validate_len(1) == RC5_32_12_16_D61_OK);
    uint8_t key[16];
    memset(key, 0, sizeof(key));
    rc5_ctx_d61_t ctx;
    rc5_setup_d61(&ctx, key);
    uint32_t blk[2] = {0U, 0U}, enc[2], dec[2];
    rc5_encrypt_d61(&ctx, blk, enc);
    assert(enc[0] == 0xeedba521U && enc[1] == 0x6d8f4b15U);
    rc5_decrypt_d61(&ctx, enc, dec);
    assert(dec[0] == blk[0] && dec[1] == blk[1]);
    assert(rc5_32_12_16_d61_verify_guard(true) == RC5_32_12_16_D61_OK);
    return 0;
}
