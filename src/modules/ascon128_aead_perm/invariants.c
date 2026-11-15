#include "interface.h"
#include <stdlib.h>
#include <string.h>

ascon128_aead_perm_err_t ascon128_aead_perm_verify_roundtrip(const uint8_t key[16], const uint8_t nonce[16], const uint8_t* pt, size_t len) {
    uint8_t* ct = (uint8_t*)malloc(len + 1);
    uint8_t* rec = (uint8_t*)malloc(len + 1);
    uint8_t tag[16];
    const uint8_t ad[4] = {'A','D','0','1'};
    if (!ct || !rec) { free(ct); free(rec); return ASCON128_AEAD_PERM_ERR_BOUNDS; }
    ascon128_aead_perm_err_t e = ascon128_aead_perm_encrypt(key, nonce, ad, 4, pt, len, ct, tag);
    if (e == ASCON128_AEAD_PERM_OK) e = ascon128_aead_perm_decrypt(key, nonce, ad, 4, ct, len, tag, rec);
    if (e == ASCON128_AEAD_PERM_OK && len > 0 && memcmp(pt, rec, len) != 0) e = ASCON128_AEAD_PERM_ERR_INVARIANT;
    free(ct); free(rec);
    return e;
}
