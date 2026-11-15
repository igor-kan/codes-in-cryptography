#include "interface.h"
#include <assert.h>

int main(void) {
    const uint8_t seed[32] = {9,8,7,6,5,4,3,2,1};
    chacha_drbg_t rng; chacha_drbg_csprng_seed(&rng, seed);
    uint8_t buf[1024];
    assert(chacha_drbg_csprng_bytes(&rng, buf, 1024) == CHACHA_DRBG_CSPRNG_OK);
    // Sanity chi-square/balance check: count 1-bits around ~4096 +- 500
    int ones = 0;
    for (int i = 0; i < 1024; ++i) for (int b = 0; b < 8; ++b) ones += (buf[i] >> b) & 1;
    assert(ones > 3600 && ones < 4600);
    return 0;
}
