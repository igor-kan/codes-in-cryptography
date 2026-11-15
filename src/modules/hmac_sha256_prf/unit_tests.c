#include "interface.h"
#include <assert.h>

int main(void) {
    assert(hmac_sha256_prf_verify_invariants() == HMAC_SHA256_PRF_OK);
    // Test long key (> 64 bytes) hashing path
    uint8_t long_key[131];
    for (int i = 0; i < 131; ++i) long_key[i] = 0xAAU;
    uint8_t out[32];
    assert(hmac_sha256_prf_mac(long_key, 131, (const uint8_t*)"test", 4, out) == HMAC_SHA256_PRF_OK);
    uint8_t okm[42];
    assert(hmac_sha256_prf_hkdf_expand(out, (const uint8_t*)"ctx", 3, okm, 42) == HMAC_SHA256_PRF_OK);
    return 0;
}
