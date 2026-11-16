#include "interface.h"
#include <string.h>

chaskey_mac_128_err_t chaskey_verify_invariants(const uint8_t key[16], const uint8_t* msg, size_t len) {
    chaskey_ctx_t ctx;
    chaskey_init(&ctx, key);
    uint8_t t1[16], t2[16];
    chaskey_mac(&ctx, msg, len, t1);
    chaskey_mac(&ctx, msg, len, t2);
    if (memcmp(t1, t2, 16) != 0) return CHASKEY_MAC_128_ERR_INVARIANT;
    if (!chaskey_verify_ct(&ctx, msg, len, t1)) return CHASKEY_MAC_128_ERR_INVARIANT;
    return CHASKEY_MAC_128_OK;
}
