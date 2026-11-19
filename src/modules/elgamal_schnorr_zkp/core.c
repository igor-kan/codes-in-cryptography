#include "interface.h"
#include <math.h>
#include <string.h>

uint64_t zkp_pow_p(uint64_t b, uint64_t e) {
    uint64_t r = 1; b %= ZKP_P;
    while (e > 0) {
        if (e & 1ULL) r = (uint64_t)(((__uint128_t)r * b) % ZKP_P);
        b = (uint64_t)(((__uint128_t)b * b) % ZKP_P);
        e >>= 1;
    }
    return r;
}
static uint64_t zkp_hash_challenge(uint64_t R, uint64_t pk, uint64_t msg) {
    uint64_t h = (R ^ pk ^ msg) * 0xbf58476d1ce4e5b9ULL;
    h = (h ^ (h >> 27)) * 0x94d049bb133111ebULL;
    return (h ^ (h >> 31)) % ZKP_Q;
}
schnorr_zkp_t schnorr_prove(uint64_t sk, uint64_t nonce_k, uint64_t msg) {
    uint64_t pk = zkp_pow_p(ZKP_G, sk);
    uint64_t R = zkp_pow_p(ZKP_G, nonce_k);
    uint64_t c = zkp_hash_challenge(R, pk, msg);
    uint64_t cx = (uint64_t)(((__uint128_t)c * sk) % ZKP_Q);
    uint64_t s = (nonce_k % ZKP_Q + cx) % ZKP_Q;
    return (schnorr_zkp_t){R, s};
}
bool schnorr_verify(uint64_t pk, uint64_t msg, schnorr_zkp_t sig) {
    uint64_t c = zkp_hash_challenge(sig.R, pk, msg);
    uint64_t lhs = zkp_pow_p(ZKP_G, sig.s);
    uint64_t rhs = (uint64_t)(((__uint128_t)sig.R * zkp_pow_p(pk, c)) % ZKP_P);
    return lhs == rhs;
}
