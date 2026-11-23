#include "interface.h"

cbc_mac_xor_d58_err_t cbc_mac_xor_d58_verify_guard(bool cond) {
    if (!cond) {
        return CBC_MAC_XOR_D58_ERR_INVARIANT;
    }
    return CBC_MAC_XOR_D58_OK;
}
