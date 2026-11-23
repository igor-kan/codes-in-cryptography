#include "interface.h"

cbc_mac_xor_d58_err_t cbc_mac_xor_d58_validate_len(size_t n) {
    if (n == 0) {
        return CBC_MAC_XOR_D58_ERR_INVALID;
    }
    return CBC_MAC_XOR_D58_OK;
}
