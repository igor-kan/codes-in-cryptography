#ifndef FROST_THRESHOLD_COMBINE_ERRORS_H
#define FROST_THRESHOLD_COMBINE_ERRORS_H

typedef enum frost_threshold_combine_err {
    FROST_THRESHOLD_COMBINE_OK = 0,
    FROST_THRESHOLD_COMBINE_ERR_NULL = -1,
    FROST_THRESHOLD_COMBINE_ERR_BOUNDS = -2,
    FROST_THRESHOLD_COMBINE_ERR_INVALID = -3,
    FROST_THRESHOLD_COMBINE_ERR_OVERFLOW = -4,
    FROST_THRESHOLD_COMBINE_ERR_INVARIANT = -5
} frost_threshold_combine_err_t;



static inline const char* frost_threshold_combine_err_str(frost_threshold_combine_err_t err) {
    switch (err) {
        case FROST_THRESHOLD_COMBINE_OK: return "ok";
        case FROST_THRESHOLD_COMBINE_ERR_NULL: return "null pointer supplied";
        case FROST_THRESHOLD_COMBINE_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case FROST_THRESHOLD_COMBINE_ERR_INVALID: return "domain precondition violated";
        case FROST_THRESHOLD_COMBINE_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case FROST_THRESHOLD_COMBINE_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* FROST_THRESHOLD_COMBINE_ERRORS_H */
