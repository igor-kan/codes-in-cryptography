#include "interface.h"

hmac_xor_pad_mac_d56_err_t hmac_xor_pad_mac_d56_validate_len(size_t n) {
    if (n == 0) {
        return HMAC_XOR_PAD_MAC_D56_ERR_INVALID;
    }
    return HMAC_XOR_PAD_MAC_D56_OK;
}
