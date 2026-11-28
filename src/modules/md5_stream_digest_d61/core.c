#include "interface.h"
#include <math.h>
#include <string.h>

static uint32_t md5_rotl(uint32_t x, uint32_t c) {
    return (x << c) | (x >> (32U - c));
}
static const uint32_t md5_k_d61[64] = {
    0xd76aa478U, 0xe8c7b756U, 0x242070dbU, 0xc1bdceeeU,
    0xf57c0fafU, 0x4787c62aU, 0xa8304613U, 0xfd469501U,
    0x698098d8U, 0x8b44f7afU, 0xffff5bb1U, 0x895cd7beU,
    0x6b901122U, 0xfd987193U, 0xa679438eU, 0x49b40821U,
    0xf61e2562U, 0xc040b340U, 0x265e5a51U, 0xe9b6c7aaU,
    0xd62f105dU, 0x02441453U, 0xd8a1e681U, 0xe7d3fbc8U,
    0x21e1cde6U, 0xc33707d6U, 0xf4d50d87U, 0x455a14edU,
    0xa9e3e905U, 0xfcefa3f8U, 0x676f02d9U, 0x8d2a4c8aU,
    0xfffa3942U, 0x8771f681U, 0x6d9d6122U, 0xfde5380cU,
    0xa4beea44U, 0x4bdecfa9U, 0xf6bb4b60U, 0xbebfbc70U,
    0x289b7ec6U, 0xeaa127faU, 0xd4ef3085U, 0x04881d05U,
    0xd9d4d039U, 0xe6db99e5U, 0x1fa27cf8U, 0xc4ac5665U,
    0xf4292244U, 0x432aff97U, 0xab9423a7U, 0xfc93a039U,
    0x655b59c3U, 0x8f0ccc92U, 0xffeff47dU, 0x85845dd1U,
    0x6fa87e4fU, 0xfe2ce6e0U, 0xa3014314U, 0x4e0811a1U,
    0xf7537e82U, 0xbd3af235U, 0x2ad7d2bbU, 0xeb86d391U
};
static const uint32_t md5_s_d61[64] = {
    7U, 12U, 17U, 22U, 7U, 12U, 17U, 22U, 7U, 12U, 17U, 22U, 7U, 12U, 17U, 22U,
    5U, 9U, 14U, 20U, 5U, 9U, 14U, 20U, 5U, 9U, 14U, 20U, 5U, 9U, 14U, 20U,
    4U, 11U, 16U, 23U, 4U, 11U, 16U, 23U, 4U, 11U, 16U, 23U, 4U, 11U, 16U, 23U,
    6U, 10U, 15U, 21U, 6U, 10U, 15U, 21U, 6U, 10U, 15U, 21U, 6U, 10U, 15U, 21U
};
static void md5_transform_d61(uint32_t st[4], const uint8_t block[64]) {
    uint32_t m[16];
    for (uint32_t i = 0; i < 16U; ++i) {
        m[i] = (uint32_t)block[i * 4U]
             | ((uint32_t)block[i * 4U + 1U] << 8)
             | ((uint32_t)block[i * 4U + 2U] << 16)
             | ((uint32_t)block[i * 4U + 3U] << 24);
    }
    uint32_t a = st[0], b = st[1], c = st[2], d = st[3];
    for (uint32_t i = 0; i < 64U; ++i) {
        uint32_t f;
        uint32_t g;
        if (i < 16U) {
            f = (b & c) | (~b & d);
            g = i;
        } else if (i < 32U) {
            f = (d & b) | (~d & c);
            g = (5U * i + 1U) % 16U;
        } else if (i < 48U) {
            f = b ^ c ^ d;
            g = (3U * i + 5U) % 16U;
        } else {
            f = c ^ (b | ~d);
            g = (7U * i) % 16U;
        }
        uint32_t tmp = d;
        d = c;
        c = b;
        b = b + md5_rotl(a + f + md5_k_d61[i] + m[g], md5_s_d61[i]);
        a = tmp;
    }
    st[0] += a;
    st[1] += b;
    st[2] += c;
    st[3] += d;
}
void md5_init_d61(md5_ctx_d61_t* ctx) {
    if (ctx == NULL) return;
    ctx->state[0] = 0x67452301U;
    ctx->state[1] = 0xefcdab89U;
    ctx->state[2] = 0x98badcfeU;
    ctx->state[3] = 0x10325476U;
    ctx->total_len = 0ULL;
    ctx->buffered = 0U;
    memset(ctx->buffer, 0, sizeof(ctx->buffer));
}
void md5_update_d61(md5_ctx_d61_t* ctx, const uint8_t* data, size_t len) {
    if (ctx == NULL || data == NULL || len == 0U) return;
    ctx->total_len += (uint64_t)len;
    size_t offset = 0U;
    if (ctx->buffered > 0U) {
        size_t need = MD5_BLOCK_BYTES - ctx->buffered;
        size_t take = (len < need) ? len : need;
        memcpy(ctx->buffer + ctx->buffered, data, take);
        ctx->buffered += take;
        offset += take;
        if (ctx->buffered == MD5_BLOCK_BYTES) {
            md5_transform_d61(ctx->state, ctx->buffer);
            ctx->buffered = 0U;
        }
    }
    while (offset + MD5_BLOCK_BYTES <= len) {
        md5_transform_d61(ctx->state, data + offset);
        offset += MD5_BLOCK_BYTES;
    }
    if (offset < len) {
        size_t rest = len - offset;
        memcpy(ctx->buffer, data + offset, rest);
        ctx->buffered = rest;
    }
}
void md5_final_d61(md5_ctx_d61_t* ctx, uint8_t digest[16]) {
    if (ctx == NULL || digest == NULL) return;
    uint64_t bits = ctx->total_len * 8ULL;
    uint8_t pad[72];
    size_t pad_len = (ctx->buffered < 56U) ? (56U - ctx->buffered) : (120U - ctx->buffered);
    memset(pad, 0, sizeof(pad));
    pad[0] = 0x80U;
    md5_update_d61(ctx, pad, pad_len);
    uint8_t length_le[8];
    for (uint32_t i = 0; i < 8U; ++i) {
        length_le[i] = (uint8_t)((bits >> (8U * i)) & 0xffU);
    }
    md5_update_d61(ctx, length_le, 8U);
    for (uint32_t i = 0; i < 4U; ++i) {
        digest[i * 4U] = (uint8_t)(ctx->state[i] & 0xffU);
        digest[i * 4U + 1U] = (uint8_t)((ctx->state[i] >> 8) & 0xffU);
        digest[i * 4U + 2U] = (uint8_t)((ctx->state[i] >> 16) & 0xffU);
        digest[i * 4U + 3U] = (uint8_t)((ctx->state[i] >> 24) & 0xffU);
    }
}
void md5_digest_d61(const uint8_t* data, size_t len, uint8_t digest[16]) {
    md5_ctx_d61_t ctx;
    md5_init_d61(&ctx);
    if (data != NULL && len > 0U) {
        md5_update_d61(&ctx, data, len);
    }
    md5_final_d61(&ctx, digest);
}
