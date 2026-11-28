#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(rc5_32_12_16_d61_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    uint8_t key[16];
    for (int i = 0; i < 16; ++i) key[i] = (uint8_t)(i * 11 + 3);
    rc5_ctx_d61_t ctx;
    rc5_setup_d61(&ctx, key);
    uint32_t x[2] = {0x01234567U, 0x89abcdefU};
    uint32_t y[2] = {0x89abcdefU, 0x01234567U};
    uint32_t ex[2], ey[2], bx[2];
    rc5_encrypt_d61(&ctx, x, ex);
    rc5_encrypt_d61(&ctx, y, ey);
    assert(ex[0] != ey[0] || ex[1] != ey[1]);
    rc5_decrypt_d61(&ctx, ex, bx);
    assert(bx[0] == x[0] && bx[1] == x[1]);
    return 0;
}
