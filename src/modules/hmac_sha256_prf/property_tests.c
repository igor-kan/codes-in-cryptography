#include "interface.h"
#include <assert.h>

int main(void) {
    uint8_t k[16] = {1}, out1[32], out2[32];
    hmac_sha256_prf_mac(k, 16, (const uint8_t*)"alpha", 5, out1);
    hmac_sha256_prf_mac(k, 16, (const uint8_t*)"alphb", 5, out2);
    assert(!hmac_sha256_prf_ct_eq32(out1, out2));
    assert(hmac_sha256_prf_validate_okm(10000) == HMAC_SHA256_PRF_ERR_BOUNDS);
    return 0;
}
