#include "interface.h"
chacha_drbg_csprng_err_t chacha_drbg_csprng_validate(const chacha_drbg_t* rng, size_t len) {
    (void)len;
    return rng ? CHACHA_DRBG_CSPRNG_OK : CHACHA_DRBG_CSPRNG_ERR_NULL;
}
