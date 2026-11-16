#ifndef CHASKEY_MAC_128_ERRORS_H
#define CHASKEY_MAC_128_ERRORS_H

typedef enum chaskey_mac_128_err {
    CHASKEY_MAC_128_OK = 0,
    CHASKEY_MAC_128_ERR_NULL = -1,
    CHASKEY_MAC_128_ERR_BOUNDS = -2,
    CHASKEY_MAC_128_ERR_INVALID = -3,
    CHASKEY_MAC_128_ERR_OVERFLOW = -4,
    CHASKEY_MAC_128_ERR_INVARIANT = -5
} chaskey_mac_128_err_t;



static inline const char* chaskey_mac_128_err_str(chaskey_mac_128_err_t err) {
    switch (err) {
        case CHASKEY_MAC_128_OK: return "ok";
        case CHASKEY_MAC_128_ERR_NULL: return "null pointer supplied";
        case CHASKEY_MAC_128_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case CHASKEY_MAC_128_ERR_INVALID: return "domain precondition violated";
        case CHASKEY_MAC_128_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case CHASKEY_MAC_128_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* CHASKEY_MAC_128_ERRORS_H */
