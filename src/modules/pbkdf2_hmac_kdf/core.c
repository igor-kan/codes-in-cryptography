#include "interface.h"
#include <stdlib.h>
#include <string.h>

static const uint32_t SHA256_K[64] = {
  0x428a2f98U,0x71374491U,0xb5c0fbcfU,0xe9b5dba5U,0x3956c25bU,0x59f111f1U,0x923f82a4U,0xab1c5ed5U,
  0xd807aa98U,0x12835b01U,0x243185beU,0x550c7dc3U,0x72be5d74U,0x80deb1feU,0x9bdc06a7U,0xc19bf174U,
  0xe49b69c1U,0xefbe4786U,0x0fc19dc6U,0x240ca1ccU,0x2de92c6fU,0x4a7484aaU,0x5cb0a9dcU,0x76f988daU,
  0x983e5152U,0xa831c66dU,0xb00327c8U,0xbf597fc7U,0xc6e00bf3U,0xd5a79147U,0x06ca6351U,0x14292967U,
  0x27b70a85U,0x2e1b2138U,0x4d2c6dfcU,0x53380d13U,0x650a7354U,0x766a0abbU,0x81c2c92eU,0x92722c85U,
  0xa2bfe8a1U,0xa81a664bU,0xc24b8b70U,0xc76c51a3U,0xd192e819U,0xd6990624U,0xf40e3585U,0x106aa070U,
  0x19a4c116U,0x1e376c08U,0x2748774cU,0x34b0bcb5U,0x391c0cb3U,0x4ed8aa4aU,0x5b9cca4fU,0x682e6ff3U,
  0x748f82eeU,0x78a5636fU,0x84c87814U,0x8cc70208U,0x90befffaU,0xa4506cebU,0xbef9a3f7U,0xc67178f2U
};
static inline uint32_t ror32(uint32_t x, int n) { return (x >> n) | (x << (32 - n)); }
static void sha256_transform(uint32_t state[8], const uint8_t block[64]) {
    uint32_t w[64], a, b, c, d, e, f, g, h;
    for (int i = 0; i < 16; ++i) {
        w[i] = ((uint32_t)block[i*4] << 24) | ((uint32_t)block[i*4+1] << 16) | ((uint32_t)block[i*4+2] << 8) | block[i*4+3];
    }
    for (int i = 16; i < 64; ++i) {
        uint32_t s0 = ror32(w[i-15], 7) ^ ror32(w[i-15], 18) ^ (w[i-15] >> 3);
        uint32_t s1 = ror32(w[i-2], 17) ^ ror32(w[i-2], 19) ^ (w[i-2] >> 10);
        w[i] = w[i-16] + s0 + w[i-7] + s1;
    }
    a=state[0]; b=state[1]; c=state[2]; d=state[3]; e=state[4]; f=state[5]; g=state[6]; h=state[7];
    for (int i = 0; i < 64; ++i) {
        uint32_t S1 = ror32(e, 6) ^ ror32(e, 11) ^ ror32(e, 25);
        uint32_t ch = (e & f) ^ ((~e) & g);
        uint32_t t1 = h + S1 + ch + SHA256_K[i] + w[i];
        uint32_t S0 = ror32(a, 2) ^ ror32(a, 13) ^ ror32(a, 22);
        uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
        uint32_t t2 = S0 + maj;
        h=g; g=f; f=e; e=d+t1; d=c; c=b; b=a; a=t1+t2;
    }
    state[0]+=a; state[1]+=b; state[2]+=c; state[3]+=d;
    state[4]+=e; state[5]+=f; state[6]+=g; state[7]+=h;
}
static void sha256_oneshot(const uint8_t* data, size_t len, uint8_t out[32]) {
    uint32_t st[8] = {0x6a09e667U,0xbb67ae85U,0x3c6ef372U,0xa54ff53aU,0x510e527fU,0x9b05688cU,0x1f83d9abU,0x5be0cd19U};
    uint8_t blk[64];
    size_t off = 0;
    while (off + 64 <= len) { sha256_transform(st, data + off); off += 64; }
    size_t rem = len - off;
    memset(blk, 0, 64);
    if (rem > 0) memcpy(blk, data + off, rem);
    blk[rem] = 0x80U;
    if (rem >= 56) { sha256_transform(st, blk); memset(blk, 0, 64); }
    uint64_t bitlen = (uint64_t)len * 8ULL;
    for (int i = 0; i < 8; ++i) blk[56 + i] = (uint8_t)(bitlen >> (56 - i * 8));
    sha256_transform(st, blk);
    for (int i = 0; i < 8; ++i) {
        out[i*4] = (uint8_t)(st[i] >> 24); out[i*4+1] = (uint8_t)(st[i] >> 16);
        out[i*4+2] = (uint8_t)(st[i] >> 8); out[i*4+3] = (uint8_t)st[i];
    }
}

static void local_hmac256(const uint8_t* key, size_t klen, const uint8_t* msg, size_t mlen, uint8_t out[32]) {
    uint8_t kblk[64] = {0}, ipad[64], opad[64];
    if (klen > 64) sha256_oneshot(key, klen, kblk);
    else if (klen > 0) memcpy(kblk, key, klen);
    for (int i = 0; i < 64; ++i) { ipad[i] = kblk[i] ^ 0x36U; opad[i] = kblk[i] ^ 0x5cU; }
    uint8_t* buf = (uint8_t*)malloc(64 + mlen);
    memcpy(buf, ipad, 64);
    if (mlen) memcpy(buf + 64, msg, mlen);
    uint8_t ih[32]; sha256_oneshot(buf, 64 + mlen, ih);
    free(buf);
    uint8_t ob[96]; memcpy(ob, opad, 64); memcpy(ob + 64, ih, 32);
    sha256_oneshot(ob, 96, out);
}

pbkdf2_hmac_kdf_err_t pbkdf2_hmac_kdf_derive(const uint8_t* pwd, size_t plen, const uint8_t* salt, size_t slen, uint32_t iterations, uint8_t* dk, size_t dklen) {
    pbkdf2_hmac_kdf_err_t v = pbkdf2_hmac_kdf_validate(iterations, dklen);
    if (v != PBKDF2_HMAC_KDF_OK) return v;
    if (!dk || (plen > 0 && !pwd) || (slen > 0 && !salt)) return PBKDF2_HMAC_KDF_ERR_NULL;
    uint8_t* sbuf = (uint8_t*)malloc(slen + 4);
    if (!sbuf) return PBKDF2_HMAC_KDF_ERR_BOUNDS;
    if (slen) memcpy(sbuf, salt, slen);
    size_t pos = 0;
    for (uint32_t blk_idx = 1; pos < dklen; ++blk_idx) {
        sbuf[slen] = (uint8_t)(blk_idx >> 24); sbuf[slen+1] = (uint8_t)(blk_idx >> 16);
        sbuf[slen+2] = (uint8_t)(blk_idx >> 8); sbuf[slen+3] = (uint8_t)blk_idx;
        uint8_t u[32], t[32];
        local_hmac256(pwd, plen, sbuf, slen + 4, u);
        memcpy(t, u, 32);
        for (uint32_t c = 1; c < iterations; ++c) {
            local_hmac256(pwd, plen, u, 32, u);
            for (int j = 0; j < 32; ++j) t[j] ^= u[j];
        }
        size_t take = (dklen - pos < 32) ? (dklen - pos) : 32;
        memcpy(dk + pos, t, take);
        pos += take;
    }
    free(sbuf);
    return PBKDF2_HMAC_KDF_OK;
}
