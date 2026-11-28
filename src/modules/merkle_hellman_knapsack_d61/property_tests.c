#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(merkle_hellman_knapsack_d61_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    mh_key_d61_t k;
    mh_public_key_d61(&k);
    for (uint32_t m = 0U; m < 256U; ++m) {
        uint64_t c = mh_encrypt_d61(&k, (uint8_t)m);
        assert(mh_decrypt_d61(&k, c) == (uint8_t)m);
    }
    assert(mh_encrypt_d61(&k, 1U) != mh_encrypt_d61(&k, 2U));
    return 0;
}
