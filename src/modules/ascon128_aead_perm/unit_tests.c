#include "interface.h"
#include <assert.h>
#include <string.h>

int main(void) {
    const uint8_t key[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    const uint8_t nonce[16] = {15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
    const uint8_t ad[] = "authenticated-header";
    const uint8_t msg[] = "Confidential Ascon-128 payload!";
    size_t n = sizeof(msg);
    uint8_t ct[64], rec[64], tag[16];
    assert(ascon128_aead_perm_encrypt(key, nonce, ad, sizeof(ad), msg, n, ct, tag) == ASCON128_AEAD_PERM_OK);
    assert(memcmp(ct, msg, n) != 0);
    assert(ascon128_aead_perm_decrypt(key, nonce, ad, sizeof(ad), ct, n, tag, rec) == ASCON128_AEAD_PERM_OK);
    assert(memcmp(rec, msg, n) == 0);
    // Tamper tag -> must fail auth and zeroize plaintext
    tag[0] ^= 1U;
    assert(ascon128_aead_perm_decrypt(key, nonce, ad, sizeof(ad), ct, n, tag, rec) == ASCON128_AEAD_PERM_ERR_INVALID);
    assert(rec[0] == 0);
    return 0;
}
