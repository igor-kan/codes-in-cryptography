#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(fe25519_arith_d60_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    fe25519_d60_t a, b, ab, ba;
    fe25519_zero_d60(&a, 1234567ULL); a.limb[2] = 98765ULL;
    fe25519_zero_d60(&b, 7654321ULL); b.limb[3] = 55555ULL;
    fe25519_mul_d60(&ab, &a, &b);
    fe25519_mul_d60(&ba, &b, &a);
    assert(memcmp(&ab, &ba, sizeof(ab)) == 0);
    return 0;
}
