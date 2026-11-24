#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(otp_hmac_counter_d59_validate_len(1) == OTP_HMAC_COUNTER_D59_OK);
    uint32_t c0 = hotp6_generate(0x12345ULL, 0ULL);
    uint32_t c1 = hotp6_generate(0x12345ULL, 1ULL);
    assert(c0 < 1000000u && c1 < 1000000u && c0 != c1);
    assert(c0 == hotp6_generate(0x12345ULL, 0ULL));
    assert(otp_hmac_counter_d59_verify_guard(true) == OTP_HMAC_COUNTER_D59_OK);
    return 0;
}
