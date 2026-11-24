#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(rabin_miller_u64_d59_validate_len(1) == RABIN_MILLER_U64_D59_OK);
    assert(is_prime_u64(2147483647ULL) == 1);
    assert(is_prime_u64(1000000007ULL) == 1);
    assert(is_prime_u64(561ULL) == 0 && is_prime_u64(1729ULL) == 0);
    assert(rabin_miller_u64_d59_verify_guard(true) == RABIN_MILLER_U64_D59_OK);
    return 0;
}
