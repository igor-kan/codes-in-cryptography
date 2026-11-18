#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(rc6_w32_r20_block_cipher_validate_len(1) == RC6_W32_R20_BLOCK_CIPHER_OK);
    rc6_ctx_t ctx;
    uint32_t k[4] = {1, 2, 3, 4}, pt[4] = {0x11223344U, 0x55667788U, 0x99AABBCCU, 0xDDEEFF00U}, ct[4], dec[4];
    rc6_key_setup(&ctx, k);
    rc6_encrypt_block(&ctx, pt, ct);
    rc6_decrypt_block(&ctx, ct, dec);
    assert(memcmp(pt, dec, sizeof(pt)) == 0 && memcmp(pt, ct, sizeof(pt)) != 0);
    assert(rc6_w32_r20_block_cipher_verify_guard(true) == RC6_W32_R20_BLOCK_CIPHER_OK);
    return 0;
}
