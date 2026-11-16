#include "interface.h"
#include <assert.h>

int main(void) {
    uint8_t pays[4][24];
    const uint8_t* ptrs[4];
    size_t lens[4] = {21, 21, 16, 24};
    for (int t = 0; t < 4; ++t) {
        for (size_t i = 0; i < lens[t]; ++i) pays[t][i] = (uint8_t)(i + t * 5);
        pays[t][0] = 0x00;
        ptrs[t] = pays[t];
    }
    assert(b58_batch_verify_mt(ptrs, lens, 4, 2) == BASE58CHECK_BTC_CODEC_OK);
    return 0;
}
