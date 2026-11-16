#ifndef BASE58CHECK_BTC_CODEC_INTERFACE_H
#define BASE58CHECK_BTC_CODEC_INTERFACE_H

#include "types.h"
#include "errors.h"

base58check_btc_codec_err_t b58_encode(const uint8_t* src, size_t len, char* dst, size_t dst_cap, size_t* out_len);
base58check_btc_codec_err_t b58_decode(const char* src, size_t len, uint8_t* dst, size_t dst_cap, size_t* out_len);
base58check_btc_codec_err_t b58check_encode(const uint8_t* payload, size_t len, char* dst, size_t dst_cap, size_t* out_len);
base58check_btc_codec_err_t b58check_decode(const char* src, size_t len, uint8_t* dst, size_t dst_cap, size_t* out_len);
base58check_btc_codec_err_t b58_validate_alphabet(const char* src, size_t len);
base58check_btc_codec_err_t b58_batch_verify_mt(const uint8_t** payloads, const size_t* lens, size_t count, size_t num_threads);
base58check_btc_codec_err_t b58_verify_invariants(const uint8_t* payload, size_t len);

#endif /* BASE58CHECK_BTC_CODEC_INTERFACE_H */
