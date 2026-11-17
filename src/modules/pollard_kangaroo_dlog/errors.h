#ifndef POLLARD_KANGAROO_DLOG_ERRORS_H
#define POLLARD_KANGAROO_DLOG_ERRORS_H

typedef enum pollard_kangaroo_dlog_err {
    POLLARD_KANGAROO_DLOG_OK = 0,
    POLLARD_KANGAROO_DLOG_ERR_NULL = -1,
    POLLARD_KANGAROO_DLOG_ERR_BOUNDS = -2,
    POLLARD_KANGAROO_DLOG_ERR_INVALID = -3,
    POLLARD_KANGAROO_DLOG_ERR_OVERFLOW = -4,
    POLLARD_KANGAROO_DLOG_ERR_INVARIANT = -5
} pollard_kangaroo_dlog_err_t;



static inline const char* pollard_kangaroo_dlog_err_str(pollard_kangaroo_dlog_err_t err) {
    switch (err) {
        case POLLARD_KANGAROO_DLOG_OK: return "ok";
        case POLLARD_KANGAROO_DLOG_ERR_NULL: return "null pointer supplied";
        case POLLARD_KANGAROO_DLOG_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case POLLARD_KANGAROO_DLOG_ERR_INVALID: return "domain precondition violated";
        case POLLARD_KANGAROO_DLOG_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case POLLARD_KANGAROO_DLOG_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* POLLARD_KANGAROO_DLOG_ERRORS_H */
