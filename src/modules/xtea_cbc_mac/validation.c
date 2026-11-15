#include "interface.h"
xtea_cbc_mac_err_t xtea_cbc_mac_validate(const xtea_key_t* key, size_t len) {
    if (!key) return XTEA_CBC_MAC_ERR_NULL;
    if (len == 0 || (len % 8U) != 0) return XTEA_CBC_MAC_ERR_INVALID;
    return XTEA_CBC_MAC_OK;
}
