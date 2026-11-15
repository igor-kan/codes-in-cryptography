#ifndef XTEA_CBC_MAC_ERRORS_H
#define XTEA_CBC_MAC_ERRORS_H

typedef enum xtea_cbc_mac_err {
    XTEA_CBC_MAC_OK = 0,
    XTEA_CBC_MAC_ERR_NULL = -1,
    XTEA_CBC_MAC_ERR_BOUNDS = -2,
    XTEA_CBC_MAC_ERR_INVALID = -3,
    XTEA_CBC_MAC_ERR_OVERFLOW = -4,
    XTEA_CBC_MAC_ERR_INVARIANT = -5
} xtea_cbc_mac_err_t;



static inline const char* xtea_cbc_mac_err_str(xtea_cbc_mac_err_t err) {
    switch (err) {
        case XTEA_CBC_MAC_OK: return "ok";
        case XTEA_CBC_MAC_ERR_NULL: return "null pointer supplied";
        case XTEA_CBC_MAC_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case XTEA_CBC_MAC_ERR_INVALID: return "domain precondition violated";
        case XTEA_CBC_MAC_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case XTEA_CBC_MAC_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* XTEA_CBC_MAC_ERRORS_H */
