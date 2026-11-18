#include "interface.h"
#include <math.h>
#include <string.h>

static uint64_t r_pow(uint64_t b, uint64_t e, uint64_t m) {
    uint64_t r = 1; b %= m;
    while (e > 0) {
        if (e & 1ULL) r = (uint64_t)(((__uint128_t)r * b) % m);
        b = (uint64_t)(((__uint128_t)b * b) % m);
        e >>= 1;
    }
    return r;
}
uint64_t rabin_encrypt(const rabin_key_t* k, uint64_t m) {
    return (uint64_t)(((__uint128_t)m * m) % k->n);
}
void rabin_decrypt_roots(const rabin_key_t* k, uint64_t c, uint64_t roots[4]) {
    uint64_t mp = r_pow(c, (k->p + 1) / 4, k->p);
    uint64_t mq = r_pow(c, (k->q + 1) / 4, k->q);
    uint64_t yp = r_pow(k->p, k->q - 2, k->q);
    uint64_t yq = r_pow(k->q, k->p - 2, k->p);
    uint64_t t1 = (uint64_t)(((__uint128_t)mp * k->q % k->n) * yq % k->n);
    uint64_t t2 = (uint64_t)(((__uint128_t)mq * k->p % k->n) * yp % k->n);
    roots[0] = (t1 + t2) % k->n;
    roots[1] = k->n - roots[0];
    roots[2] = (t1 + k->n - t2) % k->n;
    roots[3] = k->n - roots[2];
}
