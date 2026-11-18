#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(poly1305_r_clamping_tag_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    uint8_t raw[32] = {1,2,3,4,5,6,7,8};
    poly1305_key_t pk; poly1305_clamp_key(raw, &pk);
    uint64_t b[1] = {42ULL};
    assert(poly1305_short_tag64(&pk, b, 1) != 0ULL);
    return 0;
}
