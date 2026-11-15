#include "interface.h"
chacha_drbg_csprng_err_t chacha_drbg_csprng_fork_stream(chacha_drbg_t* parent, chacha_drbg_t* child) {
    if (!parent || !child) return CHACHA_DRBG_CSPRNG_ERR_NULL;
    uint8_t child_seed[32];
    chacha_drbg_csprng_err_t e = chacha_drbg_csprng_bytes(parent, child_seed, 32);
    if (e != CHACHA_DRBG_CSPRNG_OK) return e;
    chacha_drbg_csprng_seed(child, child_seed);
    return CHACHA_DRBG_CSPRNG_OK;
}
