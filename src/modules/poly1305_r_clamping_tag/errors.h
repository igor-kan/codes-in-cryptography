#ifndef POLY1305_R_CLAMPING_TAG_ERRORS_H
#define POLY1305_R_CLAMPING_TAG_ERRORS_H

typedef enum poly1305_r_clamping_tag_err {
    POLY1305_R_CLAMPING_TAG_OK = 0,
    POLY1305_R_CLAMPING_TAG_ERR_NULL = -1,
    POLY1305_R_CLAMPING_TAG_ERR_BOUNDS = -2,
    POLY1305_R_CLAMPING_TAG_ERR_INVALID = -3,
    POLY1305_R_CLAMPING_TAG_ERR_OVERFLOW = -4,
    POLY1305_R_CLAMPING_TAG_ERR_INVARIANT = -5
} poly1305_r_clamping_tag_err_t;



static inline const char* poly1305_r_clamping_tag_err_str(poly1305_r_clamping_tag_err_t err) {
    switch (err) {
        case POLY1305_R_CLAMPING_TAG_OK: return "ok";
        case POLY1305_R_CLAMPING_TAG_ERR_NULL: return "null pointer supplied";
        case POLY1305_R_CLAMPING_TAG_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case POLY1305_R_CLAMPING_TAG_ERR_INVALID: return "domain precondition violated";
        case POLY1305_R_CLAMPING_TAG_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case POLY1305_R_CLAMPING_TAG_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* POLY1305_R_CLAMPING_TAG_ERRORS_H */
