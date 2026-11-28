#include "interface.h"
#include <math.h>
#include <string.h>

static const uint64_t mh_private_d61[MH_BITS] = {2ULL, 3ULL, 7ULL, 14ULL, 30ULL, 57ULL, 120ULL, 251ULL};
static uint64_t mh_modinv(uint64_t a, uint64_t m) {
    int64_t t = 0, new_t = 1;
    int64_t r = (int64_t)m, new_r = (int64_t)a;
    while (new_r != 0) {
        int64_t q = r / new_r;
        int64_t tmp = t - q * new_t;
        t = new_t;
        new_t = tmp;
        tmp = r - q * new_r;
        r = new_r;
        new_r = tmp;
    }
    if (t < 0) t += (int64_t)m;
    return (uint64_t)t;
}
void mh_public_key_d61(mh_key_d61_t* k) {
    k->modulus = MH_MODULUS;
    k->inverse = mh_modinv(MH_MULTIPLIER, MH_MODULUS);
    for (int i = 0; i < MH_BITS; ++i) {
        k->public_key[i] = (MH_MULTIPLIER * mh_private_d61[i]) % MH_MODULUS;
    }
}
uint64_t mh_encrypt_d61(const mh_key_d61_t* k, uint8_t msg) {
    uint64_t ct = 0ULL;
    for (int i = 0; i < MH_BITS; ++i) {
        if ((msg >> i) & 1U) ct += k->public_key[i];
    }
    return ct;
}
uint8_t mh_decrypt_d61(const mh_key_d61_t* k, uint64_t ct) {
    uint64_t rest = (uint64_t)(((__uint128_t)(ct % k->modulus) * k->inverse) % k->modulus);
    uint8_t msg = 0U;
    for (int i = MH_BITS - 1; i >= 0; --i) {
        if (rest >= mh_private_d61[i]) {
            rest -= mh_private_d61[i];
            msg |= (uint8_t)(1U << i);
        }
    }
    return msg;
}
