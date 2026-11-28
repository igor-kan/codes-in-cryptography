#include "interface.h"
#include <math.h>
#include <string.h>

static uint32_t rmd_rotl(uint32_t x, uint32_t c) {
    return (x << c) | (x >> (32U - c));
}
static const uint32_t rmd_r_d61[80] = {
    0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U, 12U, 13U, 14U, 15U,
    7U, 4U, 13U, 1U, 10U, 6U, 15U, 3U, 12U, 0U, 9U, 5U, 2U, 14U, 11U, 8U,
    3U, 10U, 14U, 4U, 9U, 15U, 8U, 1U, 2U, 7U, 0U, 6U, 13U, 11U, 5U, 12U,
    1U, 9U, 11U, 10U, 0U, 8U, 12U, 4U, 13U, 3U, 7U, 15U, 14U, 5U, 6U, 2U,
    4U, 0U, 5U, 9U, 7U, 12U, 2U, 10U, 14U, 1U, 3U, 8U, 11U, 6U, 15U, 13U
};
static const uint32_t rmd_rp_d61[80] = {
    5U, 14U, 7U, 0U, 9U, 2U, 11U, 4U, 13U, 6U, 15U, 8U, 1U, 10U, 3U, 12U,
    6U, 11U, 3U, 7U, 0U, 13U, 5U, 10U, 14U, 15U, 8U, 12U, 4U, 9U, 1U, 2U,
    15U, 5U, 1U, 3U, 7U, 14U, 6U, 9U, 11U, 8U, 12U, 2U, 10U, 0U, 4U, 13U,
    8U, 6U, 4U, 1U, 3U, 11U, 15U, 0U, 5U, 12U, 2U, 13U, 9U, 7U, 10U, 14U,
    12U, 15U, 10U, 4U, 1U, 5U, 8U, 7U, 6U, 2U, 13U, 14U, 0U, 3U, 9U, 11U
};
static const uint32_t rmd_s_d61[80] = {
    11U, 14U, 15U, 12U, 5U, 8U, 7U, 9U, 11U, 13U, 14U, 15U, 6U, 7U, 9U, 8U,
    7U, 6U, 8U, 13U, 11U, 9U, 7U, 15U, 7U, 12U, 15U, 9U, 11U, 7U, 13U, 12U,
    11U, 13U, 6U, 7U, 14U, 9U, 13U, 15U, 14U, 8U, 13U, 6U, 5U, 12U, 7U, 5U,
    11U, 12U, 14U, 15U, 14U, 15U, 9U, 8U, 9U, 14U, 5U, 6U, 8U, 6U, 5U, 12U,
    9U, 15U, 5U, 11U, 6U, 8U, 13U, 12U, 5U, 12U, 13U, 14U, 11U, 8U, 5U, 6U
};
static const uint32_t rmd_sp_d61[80] = {
    8U, 9U, 9U, 11U, 13U, 15U, 15U, 5U, 7U, 7U, 8U, 11U, 14U, 14U, 12U, 6U,
    9U, 13U, 15U, 7U, 12U, 8U, 9U, 11U, 7U, 7U, 12U, 7U, 6U, 15U, 13U, 11U,
    9U, 7U, 15U, 11U, 8U, 6U, 6U, 14U, 12U, 13U, 5U, 14U, 13U, 13U, 7U, 5U,
    15U, 5U, 8U, 11U, 14U, 14U, 6U, 14U, 6U, 9U, 12U, 9U, 12U, 5U, 15U, 8U,
    8U, 5U, 12U, 9U, 12U, 5U, 14U, 6U, 8U, 13U, 6U, 5U, 15U, 13U, 11U, 11U
};
static const uint32_t rmd_kl_d61[5] = {0x00000000U, 0x5a827999U, 0x6ed9eba1U, 0x8f1bbcdcU, 0xa953fd4eU};
static const uint32_t rmd_kr_d61[5] = {0x50a28be6U, 0x5c4dd124U, 0x6d703ef3U, 0x7a6d76e9U, 0x00000000U};
static uint32_t rmd_f_d61(uint32_t j, uint32_t x, uint32_t y, uint32_t z) {
    if (j < 16U) return x ^ y ^ z;
    if (j < 32U) return (x & y) | (~x & z);
    if (j < 48U) return (x | ~y) ^ z;
    if (j < 64U) return (x & z) | (y & ~z);
    return x ^ (y | ~z);
}
static void rmd_transform_d61(uint32_t st[5], const uint8_t block[64]) {
    uint32_t m[16];
    for (uint32_t i = 0; i < 16U; ++i) {
        m[i] = (uint32_t)block[i * 4U]
             | ((uint32_t)block[i * 4U + 1U] << 8)
             | ((uint32_t)block[i * 4U + 2U] << 16)
             | ((uint32_t)block[i * 4U + 3U] << 24);
    }
    uint32_t al = st[0], bl = st[1], cl = st[2], dl = st[3], el = st[4];
    uint32_t ar = st[0], br = st[1], cr = st[2], dr = st[3], er = st[4];
    for (uint32_t j = 0; j < 80U; ++j) {
        uint32_t t = rmd_rotl(al + rmd_f_d61(j, bl, cl, dl) + m[rmd_r_d61[j]] + rmd_kl_d61[j / 16U], rmd_s_d61[j]) + el;
        al = el;
        el = dl;
        dl = rmd_rotl(cl, 10U);
        cl = bl;
        bl = t;
        t = rmd_rotl(ar + rmd_f_d61(79U - j, br, cr, dr) + m[rmd_rp_d61[j]] + rmd_kr_d61[j / 16U], rmd_sp_d61[j]) + er;
        ar = er;
        er = dr;
        dr = rmd_rotl(cr, 10U);
        cr = br;
        br = t;
    }
    uint32_t t = st[1] + cl + dr;
    st[1] = st[2] + dl + er;
    st[2] = st[3] + el + ar;
    st[3] = st[4] + al + br;
    st[4] = st[0] + bl + cr;
    st[0] = t;
}
void ripemd160_init_d61(ripemd160_ctx_d61_t* ctx) {
    if (ctx == NULL) return;
    ctx->state[0] = 0x67452301U;
    ctx->state[1] = 0xefcdab89U;
    ctx->state[2] = 0x98badcfeU;
    ctx->state[3] = 0x10325476U;
    ctx->state[4] = 0xc3d2e1f0U;
    ctx->total_len = 0ULL;
    ctx->buffered = 0U;
    memset(ctx->buffer, 0, sizeof(ctx->buffer));
}
void ripemd160_update_d61(ripemd160_ctx_d61_t* ctx, const uint8_t* data, size_t len) {
    if (ctx == NULL || data == NULL || len == 0U) return;
    ctx->total_len += (uint64_t)len;
    size_t offset = 0U;
    if (ctx->buffered > 0U) {
        size_t need = RMD_BLOCK_BYTES - ctx->buffered;
        size_t take = (len < need) ? len : need;
        memcpy(ctx->buffer + ctx->buffered, data, take);
        ctx->buffered += take;
        offset += take;
        if (ctx->buffered == RMD_BLOCK_BYTES) {
            rmd_transform_d61(ctx->state, ctx->buffer);
            ctx->buffered = 0U;
        }
    }
    while (offset + RMD_BLOCK_BYTES <= len) {
        rmd_transform_d61(ctx->state, data + offset);
        offset += RMD_BLOCK_BYTES;
    }
    if (offset < len) {
        size_t rest = len - offset;
        memcpy(ctx->buffer, data + offset, rest);
        ctx->buffered = rest;
    }
}
void ripemd160_final_d61(ripemd160_ctx_d61_t* ctx, uint8_t digest[20]) {
    if (ctx == NULL || digest == NULL) return;
    uint64_t bits = ctx->total_len * 8ULL;
    uint8_t pad[72];
    size_t pad_len = (ctx->buffered < 56U) ? (56U - ctx->buffered) : (120U - ctx->buffered);
    memset(pad, 0, sizeof(pad));
    pad[0] = 0x80U;
    ripemd160_update_d61(ctx, pad, pad_len);
    uint8_t length_le[8];
    for (uint32_t i = 0; i < 8U; ++i) {
        length_le[i] = (uint8_t)((bits >> (8U * i)) & 0xffU);
    }
    ripemd160_update_d61(ctx, length_le, 8U);
    for (uint32_t i = 0; i < 5U; ++i) {
        digest[i * 4U] = (uint8_t)(ctx->state[i] & 0xffU);
        digest[i * 4U + 1U] = (uint8_t)((ctx->state[i] >> 8) & 0xffU);
        digest[i * 4U + 2U] = (uint8_t)((ctx->state[i] >> 16) & 0xffU);
        digest[i * 4U + 3U] = (uint8_t)((ctx->state[i] >> 24) & 0xffU);
    }
}
void ripemd160_digest_d61(const uint8_t* data, size_t len, uint8_t digest[20]) {
    ripemd160_ctx_d61_t ctx;
    ripemd160_init_d61(&ctx);
    if (data != NULL && len > 0U) {
        ripemd160_update_d61(&ctx, data, len);
    }
    ripemd160_final_d61(&ctx, digest);
}
