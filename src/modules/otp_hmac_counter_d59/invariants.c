#include "interface.h"

otp_hmac_counter_d59_err_t otp_hmac_counter_d59_verify_guard(bool cond) {
    if (!cond) {
        return OTP_HMAC_COUNTER_D59_ERR_INVARIANT;
    }
    return OTP_HMAC_COUNTER_D59_OK;
}
