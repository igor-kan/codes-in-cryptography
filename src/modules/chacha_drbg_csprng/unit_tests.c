#include "interface.h"
#include <assert.h>
#include <string.h>

int main(void) {
    const uint8_t seed[32] = {0x42};
    assert(chacha_drbg_csprng_check_determinism(seed) == CHACHA_DRBG_CSPRNG_OK);
    chacha_drbg_t rng;
    chacha_drbg_csprng_seed(&rng, seed);
    uint8_t b1[32], b2[32];
    chacha_drbg_csprng_bytes(&rng, b1, 32);
    chacha_drbg_csprng_bytes(&rng, b2, 32);
    assert(memcmp(b1, b2, 32) != 0);
    return 0;
}
