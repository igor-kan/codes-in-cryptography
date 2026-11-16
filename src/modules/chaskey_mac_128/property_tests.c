#include "interface.h"
#include <assert.h>

int main(void) {
    uint8_t key[16] = {9,8,7,6,5,4,3,2,1,0,9,8,7,6,5,4};
    chaskey_ctx_t ctx;
    chaskey_init(&ctx, key);
    uint8_t msgs[4][40], tags[64];
    const uint8_t* ptrs[4];
    size_t lens[4] = {0, 16, 25, 40};
    for (int i = 0; i < 4; ++i) {
        for (size_t j = 0; j < 40; ++j) msgs[i][j] = (uint8_t)(i * 11 + j);
        ptrs[i] = msgs[i];
        chaskey_mac(&ctx, ptrs[i], lens[i], tags + i * 16);
    }
    assert(chaskey_batch_verify_mt(&ctx, ptrs, lens, tags, 4, 2) == CHASKEY_MAC_128_OK);
    return 0;
}
