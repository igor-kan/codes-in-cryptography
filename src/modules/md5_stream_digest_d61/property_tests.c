#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(md5_stream_digest_d61_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    uint8_t msg[100];
    for (uint32_t i = 0; i < 100U; ++i) msg[i] = (uint8_t)(i * 13U + 7U);
    uint8_t one[16], streamed[16];
    md5_digest_d61(msg, 100U, one);
    md5_ctx_d61_t ctx;
    md5_init_d61(&ctx);
    md5_update_d61(&ctx, msg, 1U);
    md5_update_d61(&ctx, msg + 1, 62U);
    md5_update_d61(&ctx, msg + 63, 37U);
    md5_final_d61(&ctx, streamed);
    assert(memcmp(one, streamed, 16U) == 0);
    msg[50] ^= 0x01U;
    uint8_t changed[16];
    md5_digest_d61(msg, 100U, changed);
    assert(memcmp(one, changed, 16U) != 0);
    return 0;
}
