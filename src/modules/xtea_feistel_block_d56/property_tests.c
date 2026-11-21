#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(xtea_feistel_block_d56_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    uint32_t k[4] = {1u, 2u, 3u, 4u};
    uint32_t a[2] = {77u, 88u};
    uint32_t b[2] = {77u, 88u};
    xtea_encrypt_block(a, k);
    xtea_decrypt_block(a, k);
    assert(a[0] == b[0] && a[1] == b[1]);
    return 0;
}
