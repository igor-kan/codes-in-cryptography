#include "interface.h"
uint64_t chacha_drbg_csprng_u64(chacha_drbg_t* rng) {
    uint8_t b[8] = {0};
    chacha_drbg_csprng_bytes(rng, b, 8);
    uint64_t v = 0;
    for (int i = 0; i < 8; ++i) v |= ((uint64_t)b[i] << (8 * i));
    return v;
}
