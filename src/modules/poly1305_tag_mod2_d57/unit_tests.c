#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(poly1305_tag_mod2_d57_validate_len(1) == POLY1305_TAG_MOD2_D57_OK);
    const uint64_t b1[3] = {10ULL, 20ULL, 30ULL};
    const uint64_t b2[3] = {10ULL, 21ULL, 30ULL};
    uint64_t t1 = cw61_mac(0x123456789ULL, 99999ULL, b1, 3);
    uint64_t t2 = cw61_mac(0x123456789ULL, 99999ULL, b2, 3);
    assert(t1 != t2 && t1 == cw61_mac(0x123456789ULL, 99999ULL, b1, 3));
    assert(poly1305_tag_mod2_d57_verify_guard(true) == POLY1305_TAG_MOD2_D57_OK);
    return 0;
}
