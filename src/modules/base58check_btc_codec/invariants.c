#include "interface.h"
#include <stdlib.h>
#include <string.h>

base58check_btc_codec_err_t b58_verify_invariants(const uint8_t* payload, size_t len) {
    size_t cap = len * 2U + 16U;
    char* enc = (char*)malloc(cap);
    uint8_t* dec = (uint8_t*)malloc(len + 16U);
    if (!enc || !dec) { free(enc); free(dec); return BASE58CHECK_BTC_CODEC_ERR_NULL; }
    size_t el = 0, dl = 0;
    if (b58check_encode(payload, len, enc, cap, &el) != BASE58CHECK_BTC_CODEC_OK ||
        b58check_decode(enc, el, dec, len + 16U, &dl) != BASE58CHECK_BTC_CODEC_OK ||
        dl != len || memcmp(payload, dec, len) != 0) {
        free(enc); free(dec); return BASE58CHECK_BTC_CODEC_ERR_INVARIANT;
    }
    free(enc); free(dec);
    return BASE58CHECK_BTC_CODEC_OK;
}
