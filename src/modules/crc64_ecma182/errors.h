#ifndef CRC64_ECMA182_ERRORS_H
#define CRC64_ECMA182_ERRORS_H

typedef enum crc64_ecma182_err {
    CRC64_ECMA182_OK = 0,
    CRC64_ECMA182_ERR_NULL = -1,
    CRC64_ECMA182_ERR_BOUNDS = -2,
    CRC64_ECMA182_ERR_INVALID = -3,
    CRC64_ECMA182_ERR_OVERFLOW = -4,
    CRC64_ECMA182_ERR_INVARIANT = -5
} crc64_ecma182_err_t;



static inline const char* crc64_ecma182_err_str(crc64_ecma182_err_t err) {
    switch (err) {
        case CRC64_ECMA182_OK: return "ok";
        case CRC64_ECMA182_ERR_NULL: return "null pointer supplied";
        case CRC64_ECMA182_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case CRC64_ECMA182_ERR_INVALID: return "domain precondition violated";
        case CRC64_ECMA182_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case CRC64_ECMA182_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* CRC64_ECMA182_ERRORS_H */
