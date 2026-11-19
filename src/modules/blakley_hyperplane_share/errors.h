#ifndef BLAKLEY_HYPERPLANE_SHARE_ERRORS_H
#define BLAKLEY_HYPERPLANE_SHARE_ERRORS_H

typedef enum blakley_hyperplane_share_err {
    BLAKLEY_HYPERPLANE_SHARE_OK = 0,
    BLAKLEY_HYPERPLANE_SHARE_ERR_NULL = -1,
    BLAKLEY_HYPERPLANE_SHARE_ERR_BOUNDS = -2,
    BLAKLEY_HYPERPLANE_SHARE_ERR_INVALID = -3,
    BLAKLEY_HYPERPLANE_SHARE_ERR_OVERFLOW = -4,
    BLAKLEY_HYPERPLANE_SHARE_ERR_INVARIANT = -5
} blakley_hyperplane_share_err_t;



static inline const char* blakley_hyperplane_share_err_str(blakley_hyperplane_share_err_t err) {
    switch (err) {
        case BLAKLEY_HYPERPLANE_SHARE_OK: return "ok";
        case BLAKLEY_HYPERPLANE_SHARE_ERR_NULL: return "null pointer supplied";
        case BLAKLEY_HYPERPLANE_SHARE_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case BLAKLEY_HYPERPLANE_SHARE_ERR_INVALID: return "domain precondition violated";
        case BLAKLEY_HYPERPLANE_SHARE_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case BLAKLEY_HYPERPLANE_SHARE_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* BLAKLEY_HYPERPLANE_SHARE_ERRORS_H */
