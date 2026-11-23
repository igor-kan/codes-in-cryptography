#ifndef CBC_MAC_XOR_D58_ERRORS_H
#define CBC_MAC_XOR_D58_ERRORS_H

typedef enum cbc_mac_xor_d58_err {
    CBC_MAC_XOR_D58_OK = 0,
    CBC_MAC_XOR_D58_ERR_NULL = -1,
    CBC_MAC_XOR_D58_ERR_BOUNDS = -2,
    CBC_MAC_XOR_D58_ERR_INVALID = -3,
    CBC_MAC_XOR_D58_ERR_OVERFLOW = -4,
    CBC_MAC_XOR_D58_ERR_INVARIANT = -5
} cbc_mac_xor_d58_err_t;



static inline const char* cbc_mac_xor_d58_err_str(cbc_mac_xor_d58_err_t err) {
    switch (err) {
        case CBC_MAC_XOR_D58_OK: return "ok";
        case CBC_MAC_XOR_D58_ERR_NULL: return "null pointer supplied";
        case CBC_MAC_XOR_D58_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case CBC_MAC_XOR_D58_ERR_INVALID: return "domain precondition violated";
        case CBC_MAC_XOR_D58_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case CBC_MAC_XOR_D58_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* CBC_MAC_XOR_D58_ERRORS_H */
