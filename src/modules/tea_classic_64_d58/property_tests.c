#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(tea_classic_64_d58_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    uint32_t k[4] = {1u, 1u, 1u, 1u}, a[2] = {7u, 8u};
    tea_encrypt(a, k); tea_decrypt(a, k);
    assert(a[0] == 7u && a[1] == 8u);
    return 0;
}
