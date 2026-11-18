#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(rc6_w32_r20_block_cipher_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    rc6_ctx_t ctx;
    uint32_t k[4] = {9, 8, 7, 6}, pt[4] = {0, 0, 0, 0}, ct[4], dec[4];
    rc6_key_setup(&ctx, k);
    rc6_encrypt_block(&ctx, pt, ct);
    rc6_decrypt_block(&ctx, ct, dec);
    assert(dec[0] == 0 && dec[3] == 0);
    return 0;
}
