#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(simon64_128_bit_d57_validate_len(1) == SIMON64_128_BIT_D57_OK);
    uint32_t key[4] = {0x03020100u, 0x0b0a0908u, 0x13121110u, 0x1b1a1918u};
    uint32_t rk[44]; simon64_expand(key, rk);
    uint32_t v[2] = {0x756e6420u, 0x656b696cu};
    simon64_enc(v, rk);
    assert(v[0] != 0x756e6420u);
    simon64_dec(v, rk);
    assert(v[0] == 0x756e6420u && v[1] == 0x656b696cu);
    assert(simon64_128_bit_d57_verify_guard(true) == SIMON64_128_BIT_D57_OK);
    return 0;
}
