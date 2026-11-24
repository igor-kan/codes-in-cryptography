#ifndef OTP_HMAC_COUNTER_D59_ERRORS_H
#define OTP_HMAC_COUNTER_D59_ERRORS_H

typedef enum otp_hmac_counter_d59_err {
    OTP_HMAC_COUNTER_D59_OK = 0,
    OTP_HMAC_COUNTER_D59_ERR_NULL = -1,
    OTP_HMAC_COUNTER_D59_ERR_BOUNDS = -2,
    OTP_HMAC_COUNTER_D59_ERR_INVALID = -3,
    OTP_HMAC_COUNTER_D59_ERR_OVERFLOW = -4,
    OTP_HMAC_COUNTER_D59_ERR_INVARIANT = -5
} otp_hmac_counter_d59_err_t;



static inline const char* otp_hmac_counter_d59_err_str(otp_hmac_counter_d59_err_t err) {
    switch (err) {
        case OTP_HMAC_COUNTER_D59_OK: return "ok";
        case OTP_HMAC_COUNTER_D59_ERR_NULL: return "null pointer supplied";
        case OTP_HMAC_COUNTER_D59_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case OTP_HMAC_COUNTER_D59_ERR_INVALID: return "domain precondition violated";
        case OTP_HMAC_COUNTER_D59_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case OTP_HMAC_COUNTER_D59_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* OTP_HMAC_COUNTER_D59_ERRORS_H */
