#include "interface.h"
#include <string.h>

base58check_btc_codec_err_t b58_validate_alphabet(const char* src, size_t len) {
    if (!src) return BASE58CHECK_BTC_CODEC_ERR_NULL;
    static const char ALPH[] = "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";
    for (size_t i = 0; i < len; ++i) {
        if (src[i] == '\0' || !strchr(ALPH, src[i])) return BASE58CHECK_BTC_CODEC_ERR_INVALID;
    }
    return BASE58CHECK_BTC_CODEC_OK;
}
