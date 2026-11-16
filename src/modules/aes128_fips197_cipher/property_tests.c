#include "interface.h"
#include <assert.h>
#include <string.h>

int main(void) {
    uint8_t key[16], pt[128], ct[128], dec[128];
    for (int i = 0; i < 16; ++i) key[i] = (uint8_t)(i * 17 + 3);
    for (int i = 0; i < 128; ++i) pt[i] = (uint8_t)(i * 7 + 11);
    aes128_ctx_t ctx;
    aes128_init(&ctx, key);
    assert(aes128_batch_ctr_mt(&ctx, pt, ct, 8, 4) == AES128_FIPS197_CIPHER_OK);
    uint8_t zero_iv[16] = {0};
    aes128_ctr_xor(&ctx, zero_iv, ct, dec, 128);
    assert(memcmp(pt, dec, 128) == 0);
    return 0;
}
