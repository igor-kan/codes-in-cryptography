#ifndef HMAC_XOR_PAD_MAC_D56_ERRORS_H
#define HMAC_XOR_PAD_MAC_D56_ERRORS_H

typedef enum hmac_xor_pad_mac_d56_err {
    HMAC_XOR_PAD_MAC_D56_OK = 0,
    HMAC_XOR_PAD_MAC_D56_ERR_NULL = -1,
    HMAC_XOR_PAD_MAC_D56_ERR_BOUNDS = -2,
    HMAC_XOR_PAD_MAC_D56_ERR_INVALID = -3,
    HMAC_XOR_PAD_MAC_D56_ERR_OVERFLOW = -4,
    HMAC_XOR_PAD_MAC_D56_ERR_INVARIANT = -5
} hmac_xor_pad_mac_d56_err_t;



static inline const char* hmac_xor_pad_mac_d56_err_str(hmac_xor_pad_mac_d56_err_t err) {
    switch (err) {
        case HMAC_XOR_PAD_MAC_D56_OK: return "ok";
        case HMAC_XOR_PAD_MAC_D56_ERR_NULL: return "null pointer supplied";
        case HMAC_XOR_PAD_MAC_D56_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case HMAC_XOR_PAD_MAC_D56_ERR_INVALID: return "domain precondition violated";
        case HMAC_XOR_PAD_MAC_D56_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case HMAC_XOR_PAD_MAC_D56_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* HMAC_XOR_PAD_MAC_D56_ERRORS_H */
