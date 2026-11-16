#include "interface.h"

chaskey_mac_128_err_t chaskey_validate(const chaskey_ctx_t* ctx, const uint8_t tag[16]) {
    if (!ctx || !tag) return CHASKEY_MAC_128_ERR_NULL;
    return CHASKEY_MAC_128_OK;
}
