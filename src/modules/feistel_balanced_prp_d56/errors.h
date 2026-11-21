#ifndef FEISTEL_BALANCED_PRP_D56_ERRORS_H
#define FEISTEL_BALANCED_PRP_D56_ERRORS_H

typedef enum feistel_balanced_prp_d56_err {
    FEISTEL_BALANCED_PRP_D56_OK = 0,
    FEISTEL_BALANCED_PRP_D56_ERR_NULL = -1,
    FEISTEL_BALANCED_PRP_D56_ERR_BOUNDS = -2,
    FEISTEL_BALANCED_PRP_D56_ERR_INVALID = -3,
    FEISTEL_BALANCED_PRP_D56_ERR_OVERFLOW = -4,
    FEISTEL_BALANCED_PRP_D56_ERR_INVARIANT = -5
} feistel_balanced_prp_d56_err_t;



static inline const char* feistel_balanced_prp_d56_err_str(feistel_balanced_prp_d56_err_t err) {
    switch (err) {
        case FEISTEL_BALANCED_PRP_D56_OK: return "ok";
        case FEISTEL_BALANCED_PRP_D56_ERR_NULL: return "null pointer supplied";
        case FEISTEL_BALANCED_PRP_D56_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case FEISTEL_BALANCED_PRP_D56_ERR_INVALID: return "domain precondition violated";
        case FEISTEL_BALANCED_PRP_D56_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case FEISTEL_BALANCED_PRP_D56_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* FEISTEL_BALANCED_PRP_D56_ERRORS_H */
