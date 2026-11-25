#include "interface.h"
#include <math.h>
#include <string.h>

static uint32_t load32_le(const uint8_t* p) {
    return (uint32_t)p[0] | ((uint32_t)p[1]<<8) | ((uint32_t)p[2]<<16) | ((uint32_t)p[3]<<24);
}
static void store32_le(uint8_t* p, uint32_t v) {
    p[0]=(uint8_t)v; p[1]=(uint8_t)(v>>8); p[2]=(uint8_t)(v>>16); p[3]=(uint8_t)(v>>24);
}
void poly1305_init_d60(poly1305_state_t* st, const uint8_t key[32]) {
    memset(st, 0, sizeof(*st));
    uint32_t t0 = load32_le(key + 0)  & 0x0fffffffU;
    uint32_t t1 = load32_le(key + 4)  & 0x0ffffffcU;
    uint32_t t2 = load32_le(key + 8)  & 0x0ffffffcU;
    uint32_t t3 = load32_le(key + 12) & 0x0ffffffcU;
    st->r[0] =  t0                        & 0x3ffffffU;
    st->r[1] = ((t0 >> 26) | (t1 << 6))   & 0x3ffffffU;
    st->r[2] = ((t1 >> 20) | (t2 << 12))  & 0x3ffffffU;
    st->r[3] = ((t2 >> 14) | (t3 << 18))  & 0x3ffffffU;
    st->r[4] =  (t3 >> 8)                 & 0x3ffffffU;
    for (int i = 0; i < 4; ++i) st->pad[i] = load32_le(key + 16 + 4 * i);
}
void poly1305_block_d60(poly1305_state_t* st, const uint8_t blk[16]) {
    uint32_t t0 = load32_le(blk + 0), t1 = load32_le(blk + 4);
    uint32_t t2 = load32_le(blk + 8), t3 = load32_le(blk + 12);
    uint32_t h0 = st->h[0] + (t0 & 0x3ffffffU);
    uint32_t h1 = st->h[1] + (((t0 >> 26) | (t1 << 6)) & 0x3ffffffU);
    uint32_t h2 = st->h[2] + (((t1 >> 20) | (t2 << 12)) & 0x3ffffffU);
    uint32_t h3 = st->h[3] + (((t2 >> 14) | (t3 << 18)) & 0x3ffffffU);
    uint32_t h4 = st->h[4] + (t3 >> 8) + (1U << 24);
    uint32_t r0=st->r[0], r1=st->r[1], r2=st->r[2], r3=st->r[3], r4=st->r[4];
    uint32_t s1=r1*5U, s2=r2*5U, s3=r3*5U, s4=r4*5U;
    uint64_t d0 = (uint64_t)h0*r0 + (uint64_t)h1*s4 + (uint64_t)h2*s3 + (uint64_t)h3*s2 + (uint64_t)h4*s1;
    uint64_t d1 = (uint64_t)h0*r1 + (uint64_t)h1*r0 + (uint64_t)h2*s4 + (uint64_t)h3*s3 + (uint64_t)h4*s2;
    uint64_t d2 = (uint64_t)h0*r2 + (uint64_t)h1*r1 + (uint64_t)h2*r0 + (uint64_t)h3*s4 + (uint64_t)h4*s3;
    uint64_t d3 = (uint64_t)h0*r3 + (uint64_t)h1*r2 + (uint64_t)h2*r1 + (uint64_t)h3*r0 + (uint64_t)h4*s4;
    uint64_t d4 = (uint64_t)h0*r4 + (uint64_t)h1*r3 + (uint64_t)h2*r2 + (uint64_t)h3*r1 + (uint64_t)h4*r0;
    uint32_t c;
    c = (uint32_t)(d0 >> 26); st->h[0] = (uint32_t)d0 & 0x3ffffffU; d1 += c;
    c = (uint32_t)(d1 >> 26); st->h[1] = (uint32_t)d1 & 0x3ffffffU; d2 += c;
    c = (uint32_t)(d2 >> 26); st->h[2] = (uint32_t)d2 & 0x3ffffffU; d3 += c;
    c = (uint32_t)(d3 >> 26); st->h[3] = (uint32_t)d3 & 0x3ffffffU; d4 += c;
    c = (uint32_t)(d4 >> 26); st->h[4] = (uint32_t)d4 & 0x3ffffffU; st->h[0] += c * 5U;
    c = st->h[0] >> 26; st->h[0] &= 0x3ffffffU; st->h[1] += c;
}
void poly1305_finish_d60(poly1305_state_t* st, uint8_t mac[16]) {
    uint32_t h0=st->h[0], h1=st->h[1], h2=st->h[2], h3=st->h[3], h4=st->h[4], c;
    c=h1>>26; h1&=0x3ffffffU; h2+=c; c=h2>>26; h2&=0x3ffffffU; h3+=c;
    c=h3>>26; h3&=0x3ffffffU; h4+=c; c=h4>>26; h4&=0x3ffffffU; h0+=c*5U;
    c=h0>>26; h0&=0x3ffffffU; h1+=c;
    uint32_t g0=h0+5U, g1=h1+(g0>>26); g0&=0x3ffffffU;
    uint32_t g2=h2+(g1>>26); g1&=0x3ffffffU;
    uint32_t g3=h3+(g2>>26); g2&=0x3ffffffU;
    uint32_t g4=h4+(g3>>26)-(1U<<26); g3&=0x3ffffffU;
    uint32_t mask = (g4 >> 31) - 1U;
    h0 = (h0 & ~mask) | (g0 & mask); h1 = (h1 & ~mask) | (g1 & mask);
    h2 = (h2 & ~mask) | (g2 & mask); h3 = (h3 & ~mask) | (g3 & mask);
    h4 = (h4 & ~mask) | (g4 & mask);
    uint64_t f0 = ((uint64_t)(h0 | (h1 << 26)) + st->pad[0]);
    uint64_t f1 = ((uint64_t)((h1 >> 6) | (h2 << 20)) + st->pad[1]) + (f0 >> 32);
    uint64_t f2 = ((uint64_t)((h2 >> 12) | (h3 << 14)) + st->pad[2]) + (f1 >> 32);
    uint64_t f3 = ((uint64_t)((h3 >> 18) | (h4 << 8)) + st->pad[3]) + (f2 >> 32);
    store32_le(mac+0, (uint32_t)f0); store32_le(mac+4, (uint32_t)f1);
    store32_le(mac+8, (uint32_t)f2); store32_le(mac+12, (uint32_t)f3);
}
