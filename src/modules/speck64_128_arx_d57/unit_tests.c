#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(speck64_128_arx_d57_validate_len(1) == SPECK64_128_ARX_D57_OK);
    uint32_t key[4] = {0x03020100u, 0x0b0a0908u, 0x13121110u, 0x1b1a1918u};
    uint32_t rk[27]; speck64_expand(key, rk);
    uint32_t v[2] = {0x7475432du, 0x3b726574u};
    speck64_enc(v, rk);
    assert(v[0] == 0x454e028bu && v[1] == 0x8c6fa548u);
    speck64_dec(v, rk);
    assert(v[0] == 0x7475432du && v[1] == 0x3b726574u);
    assert(speck64_128_arx_d57_verify_guard(true) == SPECK64_128_ARX_D57_OK);
    return 0;
}
