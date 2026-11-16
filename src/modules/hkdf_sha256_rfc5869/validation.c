#include "interface.h"

hkdf_sha256_rfc5869_err_t hkdf_validate_okm(size_t okm_len) {
    if (okm_len > 255U * 32U) return HKDF_SHA256_RFC5869_ERR_BOUNDS;
    return HKDF_SHA256_RFC5869_OK;
}
