#include "interface.h"
#include <string.h>

chacha_drbg_csprng_err_t chacha_drbg_csprng_check_determinism(const uint8_t seed[32]) {
    chacha_drbg_t a, b;
    chacha_drbg_csprng_seed(&a, seed);
    chacha_drbg_csprng_seed(&b, seed);
    uint8_t oa[100], ob[100];
    chacha_drbg_csprng_bytes(&a, oa, 100);
    chacha_drbg_csprng_bytes(&b, ob, 100);
    if (memcmp(oa, ob, 100) != 0) return CHACHA_DRBG_CSPRNG_ERR_INVARIANT;
    if (memcmp(a.key, seed, 32) == 0) return CHACHA_DRBG_CSPRNG_ERR_INVARIANT; // Fast-key-erasure check
    return CHACHA_DRBG_CSPRNG_OK;
}
