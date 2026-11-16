#include "interface.h"
#include <assert.h>
#include <string.h>

int main(void) {
    uint8_t key[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    uint8_t msg[32];
    for (int i = 0; i < 32; ++i) msg[i] = (uint8_t)i;
    assert(chaskey_verify_invariants(key, msg, 32) == CHASKEY_MAC_128_OK);
    chaskey_ctx_t ctx;
    chaskey_init(&ctx, key);
    uint8_t tag[16], bad_tag[16];
    chaskey_mac(&ctx, msg, 25, tag);
    memcpy(bad_tag, tag, 16);
    bad_tag[0] ^= 0x01;
    assert(chaskey_verify_ct(&ctx, msg, 25, tag));
    assert(!chaskey_verify_ct(&ctx, msg, 25, bad_tag));
    return 0;
}
