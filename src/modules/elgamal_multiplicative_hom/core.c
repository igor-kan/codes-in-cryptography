#include "interface.h"
#include <math.h>
#include <string.h>

uint64_t elg_pow(uint64_t b, uint64_t e) {
    uint64_t r = 1; b %= ELG_P;
    while (e > 0) {
        if (e & 1ULL) r = (uint64_t)(((__uint128_t)r * b) % ELG_P);
        b = (uint64_t)(((__uint128_t)b * b) % ELG_P);
        e >>= 1;
    }
    return r;
}
elg_cipher_t elg_encrypt(uint64_t pk, uint64_t m, uint64_t r) {
    uint64_t c1 = elg_pow(ELG_G, r);
    uint64_t s  = elg_pow(pk, r);
    uint64_t c2 = (uint64_t)(((__uint128_t)m * s) % ELG_P);
    return (elg_cipher_t){c1, c2};
}
uint64_t elg_decrypt(uint64_t sk, elg_cipher_t ct) {
    uint64_t s = elg_pow(ct.c1, sk);
    uint64_t sinv = elg_pow(s, ELG_P - 2);
    return (uint64_t)(((__uint128_t)ct.c2 * sinv) % ELG_P);
}
elg_cipher_t elg_hom_mul(elg_cipher_t a, elg_cipher_t b) {
    return (elg_cipher_t){
        (uint64_t)(((__uint128_t)a.c1 * b.c1) % ELG_P),
        (uint64_t)(((__uint128_t)a.c2 * b.c2) % ELG_P)
    };
}
