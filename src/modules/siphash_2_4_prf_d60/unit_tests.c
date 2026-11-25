#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(siphash_2_4_prf_d60_validate_len(1) == SIPHASH_2_4_PRF_D60_OK);
    uint64_t k0 = 0x0706050403020100ULL, k1 = 0x0f0e0d0c0b0a0908ULL;
    uint8_t msg[15]; for (size_t i = 0; i < 15; ++i) msg[i] = (uint8_t)i;
    assert(siphash24_d60(k0, k1, msg, 15) == 0xa129ca6149be45e5ULL);
    assert(siphash_2_4_prf_d60_verify_guard(true) == SIPHASH_2_4_PRF_D60_OK);
    return 0;
}
