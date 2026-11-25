#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(gf128_ghash_mul_d60_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    gf128_elem_t x = {0xaaaaaaaaaaaaaaaaULL, 0x5555555555555555ULL};
    gf128_elem_t a = {0x1111222233334444ULL, 0x5555666677778888ULL};
    gf128_elem_t b = {0x99990000aaaabbbbULL, 0xccccddddeeeeffffULL};
    gf128_elem_t ab = {a.hi ^ b.hi, a.lo ^ b.lo};
    gf128_elem_t lhs = gf128_mul_d60(x, ab);
    gf128_elem_t xa = gf128_mul_d60(x, a), xb = gf128_mul_d60(x, b);
    assert(lhs.hi == (xa.hi ^ xb.hi) && lhs.lo == (xa.lo ^ xb.lo));
    return 0;
}
