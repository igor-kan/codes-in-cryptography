#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(gf128_ghash_mul_d60_validate_len(1) == GF128_GHASH_MUL_D60_OK);
    gf128_elem_t one = {0x8000000000000000ULL, 0ULL};
    gf128_elem_t v = {0x123456789abcdef0ULL, 0xfedcba9876543210ULL};
    gf128_elem_t p = gf128_mul_d60(one, v);
    assert(p.hi == v.hi && p.lo == v.lo);
    assert(gf128_ghash_mul_d60_verify_guard(true) == GF128_GHASH_MUL_D60_OK);
    return 0;
}
