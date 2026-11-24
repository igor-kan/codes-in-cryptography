#ifndef OTP_HMAC_COUNTER_D59_TYPES_H
#define OTP_HMAC_COUNTER_D59_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint64_t counter;
    uint32_t code;
} hotp_token_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} otp_hmac_counter_d59_meta_t;

#endif /* OTP_HMAC_COUNTER_D59_TYPES_H */
