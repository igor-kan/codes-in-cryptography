#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(ripemd160_digest_d61_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    uint8_t msg[100];
    for (uint32_t i = 0; i < 100U; ++i) msg[i] = (uint8_t)(i * 17U + 3U);
    uint8_t one[20], streamed[20];
    ripemd160_digest_d61(msg, 100U, one);
    ripemd160_ctx_d61_t ctx;
    ripemd160_init_d61(&ctx);
    ripemd160_update_d61(&ctx, msg, 23U);
    ripemd160_update_d61(&ctx, msg + 23, 41U);
    ripemd160_update_d61(&ctx, msg + 64, 36U);
    ripemd160_final_d61(&ctx, streamed);
    assert(memcmp(one, streamed, 20U) == 0);
    msg[64] ^= 0x80U;
    uint8_t changed[20];
    ripemd160_digest_d61(msg, 100U, changed);
    assert(memcmp(one, changed, 20U) != 0);
    return 0;
}
