#ifndef CHACHA_DRBG_CSPRNG_INTERFACE_H
#define CHACHA_DRBG_CSPRNG_INTERFACE_H

#include "types.h"
#include "errors.h"

void chacha_drbg_csprng_seed(chacha_drbg_t* rng, const uint8_t seed[32]);
chacha_drbg_csprng_err_t chacha_drbg_csprng_bytes(chacha_drbg_t* rng, uint8_t* out, size_t len);
void chacha_drbg_csprng_rekey(chacha_drbg_t* rng, const uint8_t extra[32]);
chacha_drbg_csprng_err_t chacha_drbg_csprng_validate(const chacha_drbg_t* rng, size_t len);
chacha_drbg_csprng_err_t chacha_drbg_csprng_check_determinism(const uint8_t seed[32]);

#endif /* CHACHA_DRBG_CSPRNG_INTERFACE_H */
