#include "interface.h"
hmac_sha256_prf_err_t hmac_sha256_prf_validate_okm(size_t olen) {
    return (olen <= 255U * 32U) ? HMAC_SHA256_PRF_OK : HMAC_SHA256_PRF_ERR_BOUNDS;
}
