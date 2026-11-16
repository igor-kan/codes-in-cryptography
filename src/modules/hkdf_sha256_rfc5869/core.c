#include "interface.h"
#include <string.h>

static const uint32_t K256[64] = {
    0x428a2f98u,0x71374491u,0xb5c0fbcfu,0xe9b5dba5u,0x3956c25bu,0x59f111f1u,0x923f82a4u,0xab1c5ed5u,
    0xd807aa98u,0x12835b01u,0x243185beu,0x550c7dc3u,0x72be5d74u,0x80deb1feu,0x9bdc06a7u,0xc19bf174u,
    0xe49b69c1u,0xefbe4786u,0x0fc19dc6u,0x240ca1ccu,0x2de92c6fu,0x4a7484aau,0x5cb0a9dcu,0x76f988dau,
    0x983e5152u,0xa831c66du,0xb00327c8u,0xbf597fc7u,0xc6e00bf3u,0xd5a79147u,0x06ca6351u,0x14292967u,
    0x27b70a85u,0x2e1b2138u,0x4d2c6dfcu,0x53380d13u,0x650a7354u,0x766a0abbu,0x81c2c92eu,0x92722c85u,
    0xa2bfe8a1u,0xa81a664bu,0xc24b8b70u,0xc76c51a3u,0xd192e819u,0xd6990624u,0xf40e3585u,0x106aa070u,
    0x19a4c116u,0x1e376c08u,0x2748774cu,0x34b0bcb5u,0x391c0cb3u,0x4ed8aa4au,0x5b9cca4fu,0x682e6ff3u,
    0x748f82eeu,0x78a5636fu,0x84c87814u,0x8cc70208u,0x90befffau,0xa4506cebu,0xbef9a3f7u,0xc67178f2u
};

static inline uint32_t rotr32(uint32_t x, int n) { return (x >> n) | (x << (32 - n)); }

static void sha256_transform(uint32_t st[8], const uint8_t block[64]) {
    uint32_t w[64];
    for (int i = 0; i < 16; ++i) {
        w[i] = ((uint32_t)block[4*i] << 24) | ((uint32_t)block[4*i+1] << 16) |
               ((uint32_t)block[4*i+2] << 8) | (uint32_t)block[4*i+3];
    }
    for (int i = 16; i < 64; ++i) {
        uint32_t s0 = rotr32(w[i-15], 7) ^ rotr32(w[i-15], 18) ^ (w[i-15] >> 3);
        uint32_t s1 = rotr32(w[i-2], 17) ^ rotr32(w[i-2], 19) ^ (w[i-2] >> 10);
        w[i] = w[i-16] + s0 + w[i-7] + s1;
    }
    uint32_t a=st[0], b=st[1], c=st[2], d=st[3], e=st[4], f=st[5], g=st[6], h=st[7];
    for (int i = 0; i < 64; ++i) {
        uint32_t S1 = rotr32(e, 6) ^ rotr32(e, 11) ^ rotr32(e, 25);
        uint32_t ch = (e & f) ^ ((~e) & g);
        uint32_t temp1 = h + S1 + ch + K256[i] + w[i];
        uint32_t S0 = rotr32(a, 2) ^ rotr32(a, 13) ^ rotr32(a, 22);
        uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
        uint32_t temp2 = S0 + maj;
        h = g; g = f; f = e; e = d + temp1;
        d = c; c = b; b = a; a = temp1 + temp2;
    }
    st[0]+=a; st[1]+=b; st[2]+=c; st[3]+=d; st[4]+=e; st[5]+=f; st[6]+=g; st[7]+=h;
}

static void sha256_init(hkdf_sha256_ctx_t* c) {
    c->state[0]=0x6a09e667u; c->state[1]=0xbb67ae85u; c->state[2]=0x3c6ef372u; c->state[3]=0xa54ff53au;
    c->state[4]=0x510e527fu; c->state[5]=0x9b05688cu; c->state[6]=0x1f83d9abu; c->state[7]=0x5be0cd19u;
    c->bitlen = 0;
    c->buf_len = 0;
}

static void sha256_update(hkdf_sha256_ctx_t* c, const uint8_t* d, size_t len) {
    for (size_t i = 0; i < len; ++i) {
        c->buf[c->buf_len++] = d[i];
        if (c->buf_len == 64U) {
            sha256_transform(c->state, c->buf);
            c->bitlen += 512ULL;
            c->buf_len = 0;
        }
    }
}

static void sha256_final(hkdf_sha256_ctx_t* c, uint8_t out[32]) {
    uint64_t total_bits = c->bitlen + (uint64_t)c->buf_len * 8ULL;
    c->buf[c->buf_len++] = 0x80U;
    if (c->buf_len > 56U) {
        while (c->buf_len < 64U) c->buf[c->buf_len++] = 0;
        sha256_transform(c->state, c->buf);
        c->buf_len = 0;
    }
    while (c->buf_len < 56U) c->buf[c->buf_len++] = 0;
    for (int i = 0; i < 8; ++i) c->buf[56 + i] = (uint8_t)((total_bits >> ((7 - i) * 8)) & 0xFFU);
    sha256_transform(c->state, c->buf);
    for (int i = 0; i < 8; ++i) {
        out[4*i]   = (uint8_t)(c->state[i] >> 24);
        out[4*i+1] = (uint8_t)(c->state[i] >> 16);
        out[4*i+2] = (uint8_t)(c->state[i] >> 8);
        out[4*i+3] = (uint8_t)(c->state[i]);
    }
}

void hkdf_sha256_hash(const uint8_t* data, size_t len, uint8_t out[32]) {
    hkdf_sha256_ctx_t c;
    sha256_init(&c);
    if (len > 0) sha256_update(&c, data, len);
    sha256_final(&c, out);
}

void hkdf_hmac_sha256(const uint8_t* key, size_t key_len, const uint8_t* msg, size_t msg_len, uint8_t out[32]) {
    uint8_t k0[64];
    memset(k0, 0, sizeof(k0));
    if (key_len > 64U) hkdf_sha256_hash(key, key_len, k0);
    else if (key_len > 0) memcpy(k0, key, key_len);
    uint8_t ipad[64], opad[64];
    for (int i = 0; i < 64; ++i) {
        ipad[i] = k0[i] ^ 0x36U;
        opad[i] = k0[i] ^ 0x5CU;
    }
    uint8_t inner[32];
    hkdf_sha256_ctx_t ctx;
    sha256_init(&ctx);
    sha256_update(&ctx, ipad, 64);
    if (msg_len > 0) sha256_update(&ctx, msg, msg_len);
    sha256_final(&ctx, inner);
    sha256_init(&ctx);
    sha256_update(&ctx, opad, 64);
    sha256_update(&ctx, inner, 32);
    sha256_final(&ctx, out);
}

hkdf_sha256_rfc5869_err_t hkdf_extract(const uint8_t* salt, size_t salt_len, const uint8_t* ikm, size_t ikm_len, uint8_t prk[32]) {
    if (!prk || (!ikm && ikm_len > 0)) return HKDF_SHA256_RFC5869_ERR_NULL;
    uint8_t zero_salt[32];
    memset(zero_salt, 0, sizeof(zero_salt));
    if (!salt || salt_len == 0) {
        hkdf_hmac_sha256(zero_salt, 32, ikm, ikm_len, prk);
    } else {
        hkdf_hmac_sha256(salt, salt_len, ikm, ikm_len, prk);
    }
    return HKDF_SHA256_RFC5869_OK;
}

hkdf_sha256_rfc5869_err_t hkdf_expand(const uint8_t prk[32], const uint8_t* info, size_t info_len, uint8_t* okm, size_t okm_len) {
    if (!prk || !okm || (!info && info_len > 0)) return HKDF_SHA256_RFC5869_ERR_NULL;
    if (okm_len > 255U * 32U) return HKDF_SHA256_RFC5869_ERR_BOUNDS;
    uint8_t t[32];
    size_t t_len = 0, copied = 0;
    uint8_t ctr = 1;
    uint8_t k0[64];
    memcpy(k0, prk, 32);
    memset(k0 + 32, 0, 32);
    uint8_t ipad[64], opad[64];
    for (int i = 0; i < 64; ++i) { ipad[i] = k0[i] ^ 0x36U; opad[i] = k0[i] ^ 0x5CU; }
    while (copied < okm_len) {
        hkdf_sha256_ctx_t ctx;
        sha256_init(&ctx);
        sha256_update(&ctx, ipad, 64);
        if (t_len > 0) sha256_update(&ctx, t, t_len);
        if (info_len > 0) sha256_update(&ctx, info, info_len);
        sha256_update(&ctx, &ctr, 1);
        sha256_final(&ctx, t);
        sha256_init(&ctx);
        sha256_update(&ctx, opad, 64);
        sha256_update(&ctx, t, 32);
        sha256_final(&ctx, t);
        t_len = 32;
        size_t take = (okm_len - copied < 32U) ? (okm_len - copied) : 32U;
        memcpy(okm + copied, t, take);
        copied += take;
        ++ctr;
    }
    return HKDF_SHA256_RFC5869_OK;
}
