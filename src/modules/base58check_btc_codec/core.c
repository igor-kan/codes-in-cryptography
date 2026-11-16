#include "interface.h"
#include <stdlib.h>
#include <string.h>

static const char B58_ALPH[] = "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";

static inline uint32_t r32(uint32_t x, int n) { return (x >> n) | (x << (32 - n)); }

static void sha256_simple(const uint8_t* data, size_t len, uint8_t out[32]) {
    static const uint32_t K[64] = {
        0x428a2f98u,0x71374491u,0xb5c0fbcfu,0xe9b5dba5u,0x3956c25bu,0x59f111f1u,0x923f82a4u,0xab1c5ed5u,
        0xd807aa98u,0x12835b01u,0x243185beu,0x550c7dc3u,0x72be5d74u,0x80deb1feu,0x9bdc06a7u,0xc19bf174u,
        0xe49b69c1u,0xefbe4786u,0x0fc19dc6u,0x240ca1ccu,0x2de92c6fu,0x4a7484aau,0x5cb0a9dcu,0x76f988dau,
        0x983e5152u,0xa831c66du,0xb00327c8u,0xbf597fc7u,0xc6e00bf3u,0xd5a79147u,0x06ca6351u,0x14292967u,
        0x27b70a85u,0x2e1b2138u,0x4d2c6dfcu,0x53380d13u,0x650a7354u,0x766a0abbu,0x81c2c92eu,0x92722c85u,
        0xa2bfe8a1u,0xa81a664bu,0xc24b8b70u,0xc76c51a3u,0xd192e819u,0xd6990624u,0xf40e3585u,0x106aa070u,
        0x19a4c116u,0x1e376c08u,0x2748774cu,0x34b0bcb5u,0x391c0cb3u,0x4ed8aa4au,0x5b9cca4fu,0x682e6ff3u,
        0x748f82eeu,0x78a5636fu,0x84c87814u,0x8cc70208u,0x90befffau,0xa4506cebu,0xbef9a3f7u,0xc67178f2u
    };
    uint32_t st[8] = {0x6a09e667u,0xbb67ae85u,0x3c6ef372u,0xa54ff53au,0x510e527fu,0x9b05688cu,0x1f83d9abu,0x5be0cd19u};
    uint8_t blk[64];
    size_t n_blocks = (len + 9U + 63U) / 64U;
    uint64_t total_bits = (uint64_t)len * 8ULL;
    for (size_t b = 0; b < n_blocks; ++b) {
        memset(blk, 0, 64);
        for (size_t i = 0; i < 64U; ++i) {
            size_t pos = b * 64U + i;
            if (pos < len) blk[i] = data[pos];
            else if (pos == len) blk[i] = 0x80U;
        }
        if (b + 1 == n_blocks) {
            for (int i = 0; i < 8; ++i) blk[56 + i] = (uint8_t)((total_bits >> ((7 - i) * 8)) & 0xFFU);
        }
        uint32_t w[64];
        for (int i = 0; i < 16; ++i) {
            w[i] = ((uint32_t)blk[4*i]<<24)|((uint32_t)blk[4*i+1]<<16)|((uint32_t)blk[4*i+2]<<8)|blk[4*i+3];
        }
        for (int i = 16; i < 64; ++i) {
            uint32_t s0 = r32(w[i-15],7)^r32(w[i-15],18)^(w[i-15]>>3);
            uint32_t s1 = r32(w[i-2],17)^r32(w[i-2],19)^(w[i-2]>>10);
            w[i] = w[i-16]+s0+w[i-7]+s1;
        }
        uint32_t a=st[0],bv=st[1],c=st[2],d=st[3],e=st[4],f=st[5],g=st[6],h=st[7];
        for (int i = 0; i < 64; ++i) {
            uint32_t t1 = h + (r32(e,6)^r32(e,11)^r32(e,25)) + ((e&f)^((~e)&g)) + K[i] + w[i];
            uint32_t t2 = (r32(a,2)^r32(a,13)^r32(a,22)) + ((a&bv)^(a&c)^(bv&c));
            h=g; g=f; f=e; e=d+t1; d=c; c=bv; bv=a; a=t1+t2;
        }
        st[0]+=a; st[1]+=bv; st[2]+=c; st[3]+=d; st[4]+=e; st[5]+=f; st[6]+=g; st[7]+=h;
    }
    for (int i = 0; i < 8; ++i) {
        out[4*i]=(uint8_t)(st[i]>>24); out[4*i+1]=(uint8_t)(st[i]>>16);
        out[4*i+2]=(uint8_t)(st[i]>>8); out[4*i+3]=(uint8_t)(st[i]);
    }
}

base58check_btc_codec_err_t b58_encode(const uint8_t* src, size_t len, char* dst, size_t dst_cap, size_t* out_len) {
    if (!dst || !out_len || (len > 0 && !src)) return BASE58CHECK_BTC_CODEC_ERR_NULL;
    size_t zeroes = 0;
    while (zeroes < len && src[zeroes] == 0) ++zeroes;
    size_t cap = (len - zeroes) * 138U / 100U + 2U;
    uint8_t* b58 = (uint8_t*)calloc(cap, 1);
    if (!b58) return BASE58CHECK_BTC_CODEC_ERR_NULL;
    size_t length = 0;
    for (size_t i = zeroes; i < len; ++i) {
        uint32_t carry = src[i];
        size_t j = 0;
        for (size_t it = cap; (carry != 0 || j < length) && it > 0; --it, ++j) {
            carry += 256U * b58[it - 1U];
            b58[it - 1U] = (uint8_t)(carry % 58U);
            carry /= 58U;
        }
        length = j;
    }
    size_t start = cap - length;
    while (start < cap && b58[start] == 0) ++start;
    size_t total = zeroes + (cap - start);
    if (total + 1U > dst_cap) { free(b58); return BASE58CHECK_BTC_CODEC_ERR_BOUNDS; }
    for (size_t i = 0; i < zeroes; ++i) dst[i] = '1';
    for (size_t i = 0; i < cap - start; ++i) dst[zeroes + i] = B58_ALPH[b58[start + i]];
    dst[total] = '\0';
    *out_len = total;
    free(b58);
    return BASE58CHECK_BTC_CODEC_OK;
}

base58check_btc_codec_err_t b58_decode(const char* src, size_t len, uint8_t* dst, size_t dst_cap, size_t* out_len) {
    if (!src || !dst || !out_len) return BASE58CHECK_BTC_CODEC_ERR_NULL;
    if (b58_validate_alphabet(src, len) != BASE58CHECK_BTC_CODEC_OK) return BASE58CHECK_BTC_CODEC_ERR_INVALID;
    size_t zeroes = 0;
    while (zeroes < len && src[zeroes] == '1') ++zeroes;
    size_t cap = len * 733U / 1000U + 2U;
    uint8_t* b256 = (uint8_t*)calloc(cap, 1);
    if (!b256) return BASE58CHECK_BTC_CODEC_ERR_NULL;
    size_t length = 0;
    for (size_t i = zeroes; i < len; ++i) {
        const char* pos = strchr(B58_ALPH, src[i]);
        uint32_t carry = (uint32_t)(pos - B58_ALPH);
        size_t j = 0;
        for (size_t it = cap; (carry != 0 || j < length) && it > 0; --it, ++j) {
            carry += 58U * b256[it - 1U];
            b256[it - 1U] = (uint8_t)(carry & 0xFFU);
            carry >>= 8U;
        }
        length = j;
    }
    size_t start = cap - length;
    while (start < cap && b256[start] == 0) ++start;
    size_t total = zeroes + (cap - start);
    if (total > dst_cap) { free(b256); return BASE58CHECK_BTC_CODEC_ERR_BOUNDS; }
    memset(dst, 0, zeroes);
    if (cap > start) memcpy(dst + zeroes, b256 + start, cap - start);
    *out_len = total;
    free(b256);
    return BASE58CHECK_BTC_CODEC_OK;
}

base58check_btc_codec_err_t b58check_encode(const uint8_t* payload, size_t len, char* dst, size_t dst_cap, size_t* out_len) {
    if (!payload || !dst || !out_len) return BASE58CHECK_BTC_CODEC_ERR_NULL;
    uint8_t* buf = (uint8_t*)malloc(len + 4U);
    if (!buf) return BASE58CHECK_BTC_CODEC_ERR_NULL;
    memcpy(buf, payload, len);
    uint8_t h1[32], h2[32];
    sha256_simple(payload, len, h1);
    sha256_simple(h1, 32, h2);
    memcpy(buf + len, h2, 4);
    base58check_btc_codec_err_t err = b58_encode(buf, len + 4U, dst, dst_cap, out_len);
    free(buf);
    return err;
}

base58check_btc_codec_err_t b58check_decode(const char* src, size_t len, uint8_t* dst, size_t dst_cap, size_t* out_len) {
    if (!src || !dst || !out_len) return BASE58CHECK_BTC_CODEC_ERR_NULL;
    uint8_t* buf = (uint8_t*)malloc(dst_cap + 16U);
    if (!buf) return BASE58CHECK_BTC_CODEC_ERR_NULL;
    size_t raw_len = 0;
    base58check_btc_codec_err_t err = b58_decode(src, len, buf, dst_cap + 16U, &raw_len);
    if (err != BASE58CHECK_BTC_CODEC_OK || raw_len < 4U) { free(buf); return BASE58CHECK_BTC_CODEC_ERR_INVALID; }
    size_t pay_len = raw_len - 4U;
    uint8_t h1[32], h2[32];
    sha256_simple(buf, pay_len, h1);
    sha256_simple(h1, 32, h2);
    if (memcmp(buf + pay_len, h2, 4) != 0) { free(buf); return BASE58CHECK_BTC_CODEC_ERR_INVARIANT; }
    if (pay_len > dst_cap) { free(buf); return BASE58CHECK_BTC_CODEC_ERR_BOUNDS; }
    memcpy(dst, buf, pay_len);
    *out_len = pay_len;
    free(buf);
    return BASE58CHECK_BTC_CODEC_OK;
}
