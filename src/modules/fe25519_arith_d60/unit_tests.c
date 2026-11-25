#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(fe25519_arith_d60_validate_len(1) == FE25519_ARITH_D60_OK);
    fe25519_d60_t two_50, p;
    fe25519_zero_d60(&two_50, 1ULL << 50);
    fe25519_d60_t b; fe25519_zero_d60(&b, 1ULL << 50);
    fe25519_mul_d60(&p, &two_50, &b);
    assert(p.limb[1] == (1ULL << 49));
    assert(fe25519_arith_d60_verify_guard(true) == FE25519_ARITH_D60_OK);
    return 0;
}
