#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(poly1305_r_clamping_tag_validate_len(1) == POLY1305_R_CLAMPING_TAG_OK);
    uint8_t raw[32];
    for (int i = 0; i < 32; ++i) raw[i] = (uint8_t)(0xffU - i);
    poly1305_key_t pk; poly1305_clamp_key(raw, &pk);
    assert((pk.r_lo & 0x0ffffffc0fffffffULL) == pk.r_lo);
    uint64_t blks[2] = {1234ULL, 5678ULL};
    assert(poly1305_short_tag64(&pk, blks, 2) != poly1305_short_tag64(&pk, blks, 1));
    assert(poly1305_r_clamping_tag_verify_guard(true) == POLY1305_R_CLAMPING_TAG_OK);
    return 0;
}
