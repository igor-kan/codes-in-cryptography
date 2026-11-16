#include "interface.h"
#include <assert.h>
#include <string.h>

int main(void) {
    uint8_t msg[200];
    for (int i = 0; i < 200; ++i) msg[i] = (uint8_t)(i * 3);
    uint8_t d1[20], d2[20];
    sha1_oneshot(msg, 200, d1);
    sha1_ctx_t ctx;
    sha1_init(&ctx);
    for (int i = 0; i < 200; i += 17) {
        size_t take = (200 - i < 17) ? (size_t)(200 - i) : 17U;
        sha1_update(&ctx, msg + i, take);
    }
    sha1_final(&ctx, d2);
    assert(memcmp(d1, d2, 20) == 0);
    const uint8_t* ptrs[2] = {msg, msg + 10};
    size_t lens[2] = {200, 190};
    uint8_t out[40];
    assert(sha1_batch_hash_mt(ptrs, lens, out, 2, 2) == SHA1_RFC3174_COMPAT_OK);
    assert(memcmp(out, d1, 20) == 0 && memcmp(out + 20, d1, 20) != 0);
    return 0;
}
