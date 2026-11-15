#include "interface.h"
hmac_sha256_prf_err_t hmac_sha256_prf_mac_fast(const uint8_t* key, size_t klen, const uint8_t* msg, size_t mlen, uint8_t out[32]) {
    return hmac_sha256_prf_mac(key, klen, msg, mlen, out);
}
