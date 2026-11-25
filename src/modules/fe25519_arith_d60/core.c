#include "interface.h"
#include <math.h>
#include <string.h>

static void fe_reduce(fe25519_d60_t* f) {
    uint64_t mask51 = (1ULL << 51) - 1ULL;
    uint64_t c;
    c = f->limb[0] >> 51; f->limb[0] &= mask51; f->limb[1] += c;
    c = f->limb[1] >> 51; f->limb[1] &= mask51; f->limb[2] += c;
    c = f->limb[2] >> 51; f->limb[2] &= mask51; f->limb[3] += c;
    c = f->limb[3] >> 51; f->limb[3] &= mask51; f->limb[4] += c;
    c = f->limb[4] >> 51; f->limb[4] &= mask51; f->limb[0] += c * 19ULL;
    c = f->limb[0] >> 51; f->limb[0] &= mask51; f->limb[1] += c;
}
void fe25519_zero_d60(fe25519_d60_t* o, uint64_t v0) {
    memset(o, 0, sizeof(*o));
    o->limb[0] = v0;
}
void fe25519_add_d60(fe25519_d60_t* o, const fe25519_d60_t* a, const fe25519_d60_t* b) {
    for (int i = 0; i < 5; ++i) o->limb[i] = a->limb[i] + b->limb[i];
    fe_reduce(o);
}
void fe25519_mul_d60(fe25519_d60_t* o, const fe25519_d60_t* a, const fe25519_d60_t* b) {
    uint64_t a0=a->limb[0], a1=a->limb[1], a2=a->limb[2], a3=a->limb[3], a4=a->limb[4];
    uint64_t b0=b->limb[0], b1=b->limb[1], b2=b->limb[2], b3=b->limb[3], b4=b->limb[4];
    uint64_t b1_19 = b1*19ULL, b2_19 = b2*19ULL, b3_19 = b3*19ULL, b4_19 = b4*19ULL;
    __uint128_t t0 = (__uint128_t)a0*b0 + (__uint128_t)a1*b4_19 + (__uint128_t)a2*b3_19 + (__uint128_t)a3*b2_19 + (__uint128_t)a4*b1_19;
    __uint128_t t1 = (__uint128_t)a0*b1 + (__uint128_t)a1*b0    + (__uint128_t)a2*b4_19 + (__uint128_t)a3*b3_19 + (__uint128_t)a4*b2_19;
    __uint128_t t2 = (__uint128_t)a0*b2 + (__uint128_t)a1*b1    + (__uint128_t)a2*b0    + (__uint128_t)a3*b4_19 + (__uint128_t)a4*b3_19;
    __uint128_t t3 = (__uint128_t)a0*b3 + (__uint128_t)a1*b2    + (__uint128_t)a2*b1    + (__uint128_t)a3*b0    + (__uint128_t)a4*b4_19;
    __uint128_t t4 = (__uint128_t)a0*b4 + (__uint128_t)a1*b3    + (__uint128_t)a2*b2    + (__uint128_t)a3*b1    + (__uint128_t)a4*b0;
    uint64_t mask51 = (1ULL << 51) - 1ULL;
    uint64_t c;
    o->limb[0] = (uint64_t)t0 & mask51; t1 += (uint64_t)(t0 >> 51);
    o->limb[1] = (uint64_t)t1 & mask51; t2 += (uint64_t)(t1 >> 51);
    o->limb[2] = (uint64_t)t2 & mask51; t3 += (uint64_t)(t2 >> 51);
    o->limb[3] = (uint64_t)t3 & mask51; t4 += (uint64_t)(t3 >> 51);
    o->limb[4] = (uint64_t)t4 & mask51; o->limb[0] += ((uint64_t)(t4 >> 51)) * 19ULL;
    c = o->limb[0] >> 51; o->limb[0] &= mask51; o->limb[1] += c;
}
