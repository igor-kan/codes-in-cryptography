#include "interface.h"

otp_hmac_counter_d59_err_t otp_hmac_counter_d59_validate_len(size_t n) {
    if (n == 0) {
        return OTP_HMAC_COUNTER_D59_ERR_INVALID;
    }
    return OTP_HMAC_COUNTER_D59_OK;
}
