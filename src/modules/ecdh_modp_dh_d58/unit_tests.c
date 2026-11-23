#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(ecdh_modp_dh_d58_validate_len(1) == ECDH_MODP_DH_D58_OK);
    const uint64_t p = 2147483647ULL, g = 7ULL;
    uint64_t pub_a = dh_pow_mod(g, 123456ULL, p);
    uint64_t pub_b = dh_pow_mod(g, 654321ULL, p);
    assert(dh_pow_mod(pub_b, 123456ULL, p) == dh_pow_mod(pub_a, 654321ULL, p));
    assert(ecdh_modp_dh_d58_verify_guard(true) == ECDH_MODP_DH_D58_OK);
    return 0;
}
