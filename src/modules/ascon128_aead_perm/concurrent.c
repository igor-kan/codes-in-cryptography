#include "interface.h"
ascon128_aead_perm_err_t ascon128_aead_perm_batch(const uint8_t key[16], const uint8_t* pt, size_t len) {
    uint8_t nonce[16] = {1};
    return ascon128_aead_perm_verify_roundtrip(key, nonce, pt, len);
}
