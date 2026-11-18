#ifndef BABY_STEP_GIANT_STEP_DLOG_ERRORS_H
#define BABY_STEP_GIANT_STEP_DLOG_ERRORS_H

typedef enum baby_step_giant_step_dlog_err {
    BABY_STEP_GIANT_STEP_DLOG_OK = 0,
    BABY_STEP_GIANT_STEP_DLOG_ERR_NULL = -1,
    BABY_STEP_GIANT_STEP_DLOG_ERR_BOUNDS = -2,
    BABY_STEP_GIANT_STEP_DLOG_ERR_INVALID = -3,
    BABY_STEP_GIANT_STEP_DLOG_ERR_OVERFLOW = -4,
    BABY_STEP_GIANT_STEP_DLOG_ERR_INVARIANT = -5
} baby_step_giant_step_dlog_err_t;



static inline const char* baby_step_giant_step_dlog_err_str(baby_step_giant_step_dlog_err_t err) {
    switch (err) {
        case BABY_STEP_GIANT_STEP_DLOG_OK: return "ok";
        case BABY_STEP_GIANT_STEP_DLOG_ERR_NULL: return "null pointer supplied";
        case BABY_STEP_GIANT_STEP_DLOG_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case BABY_STEP_GIANT_STEP_DLOG_ERR_INVALID: return "domain precondition violated";
        case BABY_STEP_GIANT_STEP_DLOG_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case BABY_STEP_GIANT_STEP_DLOG_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* BABY_STEP_GIANT_STEP_DLOG_ERRORS_H */
