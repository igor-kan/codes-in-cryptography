#ifndef PEDERSEN_COMMIT_D60_ERRORS_H
#define PEDERSEN_COMMIT_D60_ERRORS_H

typedef enum pedersen_commit_d60_err {
    PEDERSEN_COMMIT_D60_OK = 0,
    PEDERSEN_COMMIT_D60_ERR_NULL = -1,
    PEDERSEN_COMMIT_D60_ERR_BOUNDS = -2,
    PEDERSEN_COMMIT_D60_ERR_INVALID = -3,
    PEDERSEN_COMMIT_D60_ERR_OVERFLOW = -4,
    PEDERSEN_COMMIT_D60_ERR_INVARIANT = -5
} pedersen_commit_d60_err_t;



static inline const char* pedersen_commit_d60_err_str(pedersen_commit_d60_err_t err) {
    switch (err) {
        case PEDERSEN_COMMIT_D60_OK: return "ok";
        case PEDERSEN_COMMIT_D60_ERR_NULL: return "null pointer supplied";
        case PEDERSEN_COMMIT_D60_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case PEDERSEN_COMMIT_D60_ERR_INVALID: return "domain precondition violated";
        case PEDERSEN_COMMIT_D60_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case PEDERSEN_COMMIT_D60_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* PEDERSEN_COMMIT_D60_ERRORS_H */
