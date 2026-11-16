#ifndef BASE58CHECK_BTC_CODEC_ERRORS_H
#define BASE58CHECK_BTC_CODEC_ERRORS_H

typedef enum base58check_btc_codec_err {
    BASE58CHECK_BTC_CODEC_OK = 0,
    BASE58CHECK_BTC_CODEC_ERR_NULL = -1,
    BASE58CHECK_BTC_CODEC_ERR_BOUNDS = -2,
    BASE58CHECK_BTC_CODEC_ERR_INVALID = -3,
    BASE58CHECK_BTC_CODEC_ERR_OVERFLOW = -4,
    BASE58CHECK_BTC_CODEC_ERR_INVARIANT = -5
} base58check_btc_codec_err_t;



static inline const char* base58check_btc_codec_err_str(base58check_btc_codec_err_t err) {
    switch (err) {
        case BASE58CHECK_BTC_CODEC_OK: return "ok";
        case BASE58CHECK_BTC_CODEC_ERR_NULL: return "null pointer supplied";
        case BASE58CHECK_BTC_CODEC_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case BASE58CHECK_BTC_CODEC_ERR_INVALID: return "domain precondition violated";
        case BASE58CHECK_BTC_CODEC_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case BASE58CHECK_BTC_CODEC_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* BASE58CHECK_BTC_CODEC_ERRORS_H */
