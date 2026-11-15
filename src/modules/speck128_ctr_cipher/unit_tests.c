#include "interface.h"
#include <assert.h>
#include <string.h>

int main(void) {
    assert(speck128_ctr_cipher_verify_kat() == SPECK128_CTR_CIPHER_OK);
    const uint64_t key[2] = {0x1234, 0x5678};
    speck128_rk_t rk;
    speck128_ctr_cipher_expand(key, &rk);
    const uint8_t msg[37] = "CTR stream over arbitrary length!!!!";
    uint8_t ct[37], rec[37];
    assert(speck128_ctr_cipher_ctr_crypt(&rk, 99, 0, msg, ct, 37) == SPECK128_CTR_CIPHER_OK);
    assert(speck128_ctr_cipher_ctr_crypt(&rk, 99, 0, ct, rec, 37) == SPECK128_CTR_CIPHER_OK);
    assert(memcmp(msg, rec, 37) == 0);
    return 0;
}
