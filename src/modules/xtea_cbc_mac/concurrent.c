#include "interface.h"
xtea_cbc_mac_err_t xtea_cbc_mac_batch_verify(const xtea_key_t* key, const uint32_t* blocks, size_t n) {
    if (!key || !blocks) return XTEA_CBC_MAC_ERR_NULL;
    for (size_t i = 0; i < n; ++i) {
        xtea_cbc_mac_err_t e = xtea_cbc_mac_check_bijection(key, blocks[2*i], blocks[2*i+1]);
        if (e != XTEA_CBC_MAC_OK) return e;
    }
    return XTEA_CBC_MAC_OK;
}
