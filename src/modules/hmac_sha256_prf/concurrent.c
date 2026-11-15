#include "interface.h"
hmac_sha256_prf_err_t hmac_sha256_prf_batch(const uint8_t* key, size_t klen, const uint8_t** msgs, const size_t* lens, uint8_t out[][32], size_t n) {
    for (size_t i = 0; i < n; ++i) {
        hmac_sha256_prf_err_t e = hmac_sha256_prf_mac(key, klen, msgs[i], lens[i], out[i]);
        if (e != HMAC_SHA256_PRF_OK) return e;
    }
    return HMAC_SHA256_PRF_OK;
}
