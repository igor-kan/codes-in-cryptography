#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(hmac_xor_pad_mac_d56_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    const uint8_t k1[3] = {1, 2, 3};
    const uint8_t m1[4] = {4, 5, 6, 7};
    const uint8_t m2[4] = {4, 5, 6, 8};
    assert(nested_hmac64(k1, 3, m1, 4) != nested_hmac64(k1, 3, m2, 4));
    return 0;
}
