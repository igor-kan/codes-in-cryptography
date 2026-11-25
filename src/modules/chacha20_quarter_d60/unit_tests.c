#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(chacha20_quarter_d60_validate_len(1) == CHACHA20_QUARTER_D60_OK);
    const uint32_t k[8] = {0x03020100U,0x07060504U,0x0b0a0908U,0x0f0e0d0cU,
                           0x13121110U,0x17161514U,0x1b1a1918U,0x1f1e1d1cU};
    const uint32_t n[3] = {0x09000000U, 0x4a000000U, 0x00000000U};
    uint32_t out[16];
    chacha20_block_words_d60(k, 1U, n, out);
    assert(out[0] == 0xe4e7f110U && out[15] == 0x4e3c50a2U);
    assert(chacha20_quarter_d60_verify_guard(true) == CHACHA20_QUARTER_D60_OK);
    return 0;
}
