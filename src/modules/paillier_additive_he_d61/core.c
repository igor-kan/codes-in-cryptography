#include "interface.h"
#include <math.h>
#include <string.h>

static uint64_t pail_gcd(uint64_t a, uint64_t b) {
    while (b != 0ULL) {
        uint64_t t = a % b;
        a = b;
        b = t;
    }
    return a;
}
static uint64_t pail_modpow(uint64_t base, uint64_t exp, uint64_t mod) {
    uint64_t result = 1ULL;
    base %= mod;
    while (exp > 0ULL) {
        if (exp & 1ULL) result = (uint64_t)(((__uint128_t)result * base) % mod);
        base = (uint64_t)(((__uint128_t)base * base) % mod);
        exp >>= 1;
    }
    return result;
}
static uint64_t pail_modinv(uint64_t a, uint64_t m) {
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
void paillier_keygen_d61(paillier_key_d61_t* k) {
    uint64_t p1 = PAIL_P - 1ULL, q1 = PAIL_Q - 1ULL;
    k->modulus = PAIL_N;
    k->modulus_sq = PAIL_N * PAIL_N;
    k->lambda = (p1 / pail_gcd(p1, q1)) * q1;
    k->mu = pail_modinv(k->lambda, k->modulus);
}
uint64_t paillier_encrypt_d61(uint64_t m, uint64_t r) {
    if (r == 0ULL || r >= PAIL_N || pail_gcd(r, PAIL_N) != 1ULL) return 0ULL;
    uint64_t n2 = PAIL_N * PAIL_N;
    uint64_t gm = pail_modpow(PAIL_N + 1ULL, m % PAIL_N, n2);
    uint64_t rn = pail_modpow(r, PAIL_N, n2);
    return (uint64_t)(((__uint128_t)gm * rn) % n2);
}
uint64_t paillier_decrypt_d61(uint64_t c) {
    paillier_key_d61_t k;
    paillier_keygen_d61(&k);
    uint64_t u = pail_modpow(c, k.lambda, k.modulus_sq);
    uint64_t l = (u - 1ULL) / k.modulus;
    return (uint64_t)(((__uint128_t)l * k.mu) % k.modulus);
}
bool paillier_additive_check_d61(uint64_t m1, uint64_t m2, uint64_t r1, uint64_t r2) {
    uint64_t c1 = paillier_encrypt_d61(m1, r1);
    uint64_t c2 = paillier_encrypt_d61(m2, r2);
    if (c1 == 0ULL || c2 == 0ULL) return false;
    uint64_t n2 = PAIL_N * PAIL_N;
    uint64_t prod = (uint64_t)(((__uint128_t)c1 * c2) % n2);
    return paillier_decrypt_d61(prod) == ((m1 + m2) % PAIL_N);
}
