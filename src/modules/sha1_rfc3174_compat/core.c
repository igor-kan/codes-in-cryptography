#include "interface.h"
#include <string.h>

static inline uint32_t rol32(uint32_t x, int n) { return (x << n) | (x >> (32 - n)); }

static void sha1_block(uint32_t st[5], const uint8_t blk[64]) {
    uint32_t w[80];
    for (int i = 0; i < 16; ++i) {
        w[i] = ((uint32_t)blk[4*i] << 24) | ((uint32_t)blk[4*i+1] << 16) |
               ((uint32_t)blk[4*i+2] << 8) | (uint32_t)blk[4*i+3];
    }
    for (int i = 16; i < 80; ++i) {
        w[i] = rol32(w[i-3] ^ w[i-8] ^ w[i-14] ^ w[i-16], 1);
    }
    uint32_t a=st[0], b=st[1], c=st[2], d=st[3], e=st[4];
    for (int i = 0; i < 80; ++i) {
        uint32_t f, k;
        if (i < 20)      { f = (b & c) | ((~b) & d);           k = 0x5A827999u; }
        else if (i < 40) { f = b ^ c ^ d;                      k = 0x6ED9EBA1u; }
        else if (i < 60) { f = (b & c) | (b & d) | (c & d);    k = 0x8F1BBCDCu; }
        else             { f = b ^ c ^ d;                      k = 0xCA62C1D6u; }
        uint32_t tmp = rol32(a, 5) + f + e + k + w[i];
        e = d; d = c; c = rol32(b, 30); b = a; a = tmp;
    }
    st[0]+=a; st[1]+=b; st[2]+=c; st[3]+=d; st[4]+=e;
}

void sha1_init(sha1_ctx_t* ctx) {
    ctx->state[0]=0x67452301u; ctx->state[1]=0xEFCDAB89u; ctx->state[2]=0x98BADCFEu;
    ctx->state[3]=0x10325476u; ctx->state[4]=0xC3D2E1F0u;
    ctx->count = 0;
}

void sha1_update(sha1_ctx_t* ctx, const uint8_t* data, size_t len) {
    size_t idx = (size_t)(ctx->count & 63ULL);
    ctx->count += len;
    size_t i = 0;
    if (idx > 0 && idx + len >= 64U) {
        memcpy(ctx->buf + idx, data, 64U - idx);
        sha1_block(ctx->state, ctx->buf);
        i = 64U - idx;
        idx = 0;
    }
    while (i + 64U <= len) {
        sha1_block(ctx->state, data + i);
        i += 64U;
    }
    if (i < len) memcpy(ctx->buf + idx, data + i, len - i);
}

void sha1_final(sha1_ctx_t* ctx, uint8_t digest[20]) {
    uint64_t total_bits = ctx->count * 8ULL;
    size_t idx = (size_t)(ctx->count & 63ULL);
    ctx->buf[idx++] = 0x80U;
    if (idx > 56U) {
        while (idx < 64U) ctx->buf[idx++] = 0;
        sha1_block(ctx->state, ctx->buf);
        idx = 0;
    }
    while (idx < 56U) ctx->buf[idx++] = 0;
    for (int i = 0; i < 8; ++i) ctx->buf[56 + i] = (uint8_t)((total_bits >> ((7 - i) * 8)) & 0xFFU);
    sha1_block(ctx->state, ctx->buf);
    for (int i = 0; i < 5; ++i) {
        digest[4*i]   = (uint8_t)(ctx->state[i] >> 24);
        digest[4*i+1] = (uint8_t)(ctx->state[i] >> 16);
        digest[4*i+2] = (uint8_t)(ctx->state[i] >> 8);
        digest[4*i+3] = (uint8_t)(ctx->state[i]);
    }
}
