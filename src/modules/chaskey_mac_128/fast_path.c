#include "interface.h"

int chaskey_verify_ct(const chaskey_ctx_t* ctx, const uint8_t* msg, size_t len, const uint8_t expected[16]) {
    if (!ctx || !expected || (len > 0 && !msg)) return 0;
    uint8_t actual[16];
    chaskey_mac(ctx, msg, len, actual);
    volatile uint8_t diff = 0;
    for (int i = 0; i < 16; ++i) diff |= (uint8_t)(actual[i] ^ expected[i]);
    return (diff == 0) ? 1 : 0;
}
