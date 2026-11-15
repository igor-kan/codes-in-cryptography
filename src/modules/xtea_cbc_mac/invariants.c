#include "interface.h"
xtea_cbc_mac_err_t xtea_cbc_mac_check_bijection(const xtea_key_t* key, uint32_t v0, uint32_t v1) {
    uint32_t blk[2] = {v0, v1};
    xtea_cbc_mac_encrypt_block(key, blk);
    xtea_cbc_mac_decrypt_block(key, blk);
    return (blk[0] == v0 && blk[1] == v1) ? XTEA_CBC_MAC_OK : XTEA_CBC_MAC_ERR_INVARIANT;
}
