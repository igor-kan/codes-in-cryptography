#include "interface.h"

hchacha20_xchacha_kdf_err_t hchacha20_validate_ptrs(const uint8_t* k, const uint8_t* n, const uint8_t* out) {
    if (!k || !n || !out) return HCHACHA20_XCHACHA_KDF_ERR_NULL;
    return HCHACHA20_XCHACHA_KDF_OK;
}
