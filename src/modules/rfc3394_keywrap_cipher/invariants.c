#include "interface.h"

rfc3394_keywrap_cipher_err_t rfc3394_verify_tamper_detection(kek128_t kek, const uint64_t* pt, size_t n) {
    uint64_t ct[65], rec[64];
    if (rfc3394_wrap(kek, pt, n, ct) != RFC3394_KEYWRAP_CIPHER_OK) return RFC3394_KEYWRAP_CIPHER_ERR_INVALID;
    if (rfc3394_unwrap(kek, ct, n, rec) != RFC3394_KEYWRAP_CIPHER_OK) return RFC3394_KEYWRAP_CIPHER_ERR_INVARIANT;
    for (size_t i = 0; i < n; ++i) {
        if (rec[i] != pt[i]) return RFC3394_KEYWRAP_CIPHER_ERR_INVARIANT;
    }
    ct[1] ^= 1ULL;
    if (rfc3394_unwrap(kek, ct, n, rec) == RFC3394_KEYWRAP_CIPHER_OK) return RFC3394_KEYWRAP_CIPHER_ERR_INVARIANT;
    return RFC3394_KEYWRAP_CIPHER_OK;
}
