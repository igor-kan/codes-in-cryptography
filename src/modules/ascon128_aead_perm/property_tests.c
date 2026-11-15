#include "interface.h"
#include <assert.h>

int main(void) {
    const uint8_t key[16] = {0xAA};
    uint8_t nonce[16] = {0x55};
    uint8_t buf[64];
    for (size_t i = 0; i < 64; ++i) buf[i] = (uint8_t)(i * 11 + 3);
    for (size_t len = 0; len <= 33; ++len) {
        nonce[0] = (uint8_t)len;
        assert(ascon128_aead_perm_verify_roundtrip(key, nonce, buf, len) == ASCON128_AEAD_PERM_OK);
    }
    return 0;
}
