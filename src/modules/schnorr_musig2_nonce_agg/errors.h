#ifndef SCHNORR_MUSIG2_NONCE_AGG_ERRORS_H
#define SCHNORR_MUSIG2_NONCE_AGG_ERRORS_H

typedef enum schnorr_musig2_nonce_agg_err {
    SCHNORR_MUSIG2_NONCE_AGG_OK = 0,
    SCHNORR_MUSIG2_NONCE_AGG_ERR_NULL = -1,
    SCHNORR_MUSIG2_NONCE_AGG_ERR_BOUNDS = -2,
    SCHNORR_MUSIG2_NONCE_AGG_ERR_INVALID = -3,
    SCHNORR_MUSIG2_NONCE_AGG_ERR_OVERFLOW = -4,
    SCHNORR_MUSIG2_NONCE_AGG_ERR_INVARIANT = -5
} schnorr_musig2_nonce_agg_err_t;



static inline const char* schnorr_musig2_nonce_agg_err_str(schnorr_musig2_nonce_agg_err_t err) {
    switch (err) {
        case SCHNORR_MUSIG2_NONCE_AGG_OK: return "ok";
        case SCHNORR_MUSIG2_NONCE_AGG_ERR_NULL: return "null pointer supplied";
        case SCHNORR_MUSIG2_NONCE_AGG_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case SCHNORR_MUSIG2_NONCE_AGG_ERR_INVALID: return "domain precondition violated";
        case SCHNORR_MUSIG2_NONCE_AGG_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case SCHNORR_MUSIG2_NONCE_AGG_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* SCHNORR_MUSIG2_NONCE_AGG_ERRORS_H */
