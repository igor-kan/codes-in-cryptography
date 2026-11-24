#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(aes_subbytes_sbox_d59_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    assert(aes_sbox_alg(0xFFu) == 0x16u && aes_inv_sbox_alg(0x16u) == 0xFFu);
    return 0;
}
