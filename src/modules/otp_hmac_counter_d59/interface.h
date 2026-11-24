#ifndef OTP_HMAC_COUNTER_D59_INTERFACE_H
#define OTP_HMAC_COUNTER_D59_INTERFACE_H

#include "types.h"
#include "errors.h"

uint32_t hotp6_generate(uint64_t key, uint64_t counter);

otp_hmac_counter_d59_err_t otp_hmac_counter_d59_validate_len(size_t n);
uint64_t otp_hmac_counter_d59_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t otp_hmac_counter_d59_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
otp_hmac_counter_d59_err_t otp_hmac_counter_d59_verify_guard(bool cond);

#endif /* OTP_HMAC_COUNTER_D59_INTERFACE_H */
