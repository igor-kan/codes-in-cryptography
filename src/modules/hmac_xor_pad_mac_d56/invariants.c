#include "interface.h"

hmac_xor_pad_mac_d56_err_t hmac_xor_pad_mac_d56_verify_guard(bool cond) {
    if (!cond) {
        return HMAC_XOR_PAD_MAC_D56_ERR_INVARIANT;
    }
    return HMAC_XOR_PAD_MAC_D56_OK;
}
