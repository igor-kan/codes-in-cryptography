#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(threefish256_arx_d61_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    uint64_t k2[4] = {1ULL, 2ULL, 3ULL, 4ULL}, tw2[2] = {5ULL, 6ULL};
    uint64_t p1[4] = {0ULL, 0ULL, 0ULL, 0ULL};
    uint64_t p2[4] = {0ULL, 0ULL, 0ULL, 1ULL};
    uint64_t c1[4], c2[4], r1[4];
    threefish256_encrypt_d61(k2, tw2, p1, c1);
    threefish256_encrypt_d61(k2, tw2, p2, c2);
    assert(c1[0] != c2[0] || c1[1] != c2[1] || c1[2] != c2[2] || c1[3] != c2[3]);
    threefish256_decrypt_d61(k2, tw2, c1, r1);
    assert(memcmp(r1, p1, sizeof(r1)) == 0);
    return 0;
}
