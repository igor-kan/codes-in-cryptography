#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(gcm_ghash_gf128_d58_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    uint64_t h = 0xCAFEBABE12345678ULL;
    assert(gf64_mul(h, 0x11ULL ^ 0x22ULL) == (gf64_mul(h, 0x11ULL) ^ gf64_mul(h, 0x22ULL)));
    return 0;
}
