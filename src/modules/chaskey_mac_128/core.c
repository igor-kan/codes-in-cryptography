#include "interface.h"
#include <string.h>

static inline uint32_t r32_c(uint32_t x, int n) { return (x >> n) | (x << (32 - n)); }

static void chaskey_perm12(uint32_t v[4]) {
    for (int r = 0; r < 12; ++r) {
        v[0] += v[1]; v[1] = r32_c(v[1], 27); v[1] ^= v[0]; v[0] = r32_c(v[0], 16);
        v[2] += v[3]; v[3] = r32_c(v[3], 24); v[3] ^= v[2];
        v[0] += v[3]; v[3] = r32_c(v[3], 19); v[3] ^= v[0];
        v[2] += v[1]; v[1] = r32_c(v[1], 25); v[1] ^= v[2]; v[2] = r32_c(v[2], 16);
    }
}

static void times_two(uint32_t out[4], const uint32_t in[4]) {
    uint32_t carry = (in[3] >> 31) ? 0x00000087U : 0U;
    out[0] = (in[0] << 1) ^ carry;
    out[1] = (in[1] << 1) | (in[0] >> 31);
    out[2] = (in[2] << 1) | (in[1] >> 31);
    out[3] = (in[3] << 1) | (in[2] >> 31);
}

static inline uint32_t load_le32(const uint8_t* p) {
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

void chaskey_init(chaskey_ctx_t* ctx, const uint8_t key[16]) {
    for (int i = 0; i < 4; ++i) ctx->k[i] = load_le32(key + 4 * i);
    times_two(ctx->k1, ctx->k);
    times_two(ctx->k2, ctx->k1);
}

void chaskey_mac(const chaskey_ctx_t* ctx, const uint8_t* msg, size_t len, uint8_t tag[16]) {
    uint32_t v[4];
    memcpy(v, ctx->k, sizeof(v));
    size_t off = 0;
    while (off + 16U < len) {
        for (int i = 0; i < 4; ++i) v[i] ^= load_le32(msg + off + 4 * i);
        chaskey_perm12(v);
        off += 16U;
    }
    const uint32_t* sub = ctx->k1;
    uint8_t last[16];
    memset(last, 0, 16);
    size_t rem = len - off;
    if (rem == 16U && len > 0) {
        memcpy(last, msg + off, 16);
    } else {
        if (rem > 0 && msg) memcpy(last, msg + off, rem);
        last[rem] = 0x01U;
        sub = ctx->k2;
    }
    for (int i = 0; i < 4; ++i) v[i] ^= load_le32(last + 4 * i) ^ sub[i];
    chaskey_perm12(v);
    for (int i = 0; i < 4; ++i) {
        v[i] ^= sub[i];
        tag[4*i]   = (uint8_t)(v[i]);
        tag[4*i+1] = (uint8_t)(v[i] >> 8);
        tag[4*i+2] = (uint8_t)(v[i] >> 16);
        tag[4*i+3] = (uint8_t)(v[i] >> 24);
    }
}
