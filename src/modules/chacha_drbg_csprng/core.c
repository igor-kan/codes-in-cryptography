#include "interface.h"
#include <string.h>

static inline uint32_t rotl32(uint32_t x, int n) { return (x << n) | (x >> (32 - n)); }
static inline uint32_t ld32(const uint8_t* p) {
    return (uint32_t)p[0] | ((uint32_t)p[1]<<8) | ((uint32_t)p[2]<<16) | ((uint32_t)p[3]<<24);
}
#define CC_QR(a,b,c,d) do { a+=b; d=rotl32(d^a,16); c+=d; b=rotl32(b^c,12); a+=b; d=rotl32(d^a,8); c+=d; b=rotl32(b^c,7); } while(0)

static void chacha20_core_blk(const uint8_t key[32], uint64_t ctr, uint8_t out[64]) {
    uint32_t in[16] = {
        0x61707865U, 0x3320646eU, 0x79622d32U, 0x6b206574U,
        ld32(key), ld32(key+4), ld32(key+8), ld32(key+12),
        ld32(key+16), ld32(key+20), ld32(key+24), ld32(key+28),
        (uint32_t)ctr, (uint32_t)(ctr >> 32), 0, 0
    };
    uint32_t x[16]; memcpy(x, in, sizeof(x));
    for (int i = 0; i < 10; ++i) {
        CC_QR(x[0],x[4],x[8],x[12]); CC_QR(x[1],x[5],x[9],x[13]);
        CC_QR(x[2],x[6],x[10],x[14]); CC_QR(x[3],x[7],x[11],x[15]);
        CC_QR(x[0],x[5],x[10],x[15]); CC_QR(x[1],x[6],x[11],x[12]);
        CC_QR(x[2],x[7],x[8],x[13]); CC_QR(x[3],x[4],x[9],x[14]);
    }
    for (int i = 0; i < 16; ++i) {
        uint32_t w = x[i] + in[i];
        out[4*i] = (uint8_t)w; out[4*i+1] = (uint8_t)(w>>8);
        out[4*i+2] = (uint8_t)(w>>16); out[4*i+3] = (uint8_t)(w>>24);
    }
}

void chacha_drbg_csprng_seed(chacha_drbg_t* rng, const uint8_t seed[32]) {
    if (!rng || !seed) return;
    memcpy(rng->key, seed, 32);
    rng->counter = 0;
}

chacha_drbg_csprng_err_t chacha_drbg_csprng_bytes(chacha_drbg_t* rng, uint8_t* out, size_t len) {
    if (!rng || (len > 0 && !out)) return CHACHA_DRBG_CSPRNG_ERR_NULL;
    uint8_t blk[64];
    // Fast-key-erasure: first 32 bytes become next key; remaining 32 bytes emitted (plus full 64-byte blocks)
    chacha20_core_blk(rng->key, rng->counter++, blk);
    uint8_t next_key[32];
    memcpy(next_key, blk, 32);
    size_t pos = 0;
    size_t take0 = (len < 32) ? len : 32;
    if (take0) { memcpy(out, blk + 32, take0); pos += take0; }
    while (pos < len) {
        chacha20_core_blk(rng->key, rng->counter++, blk);
        size_t take = (len - pos < 64) ? (len - pos) : 64;
        memcpy(out + pos, blk, take);
        pos += take;
    }
    memcpy(rng->key, next_key, 32);
    return CHACHA_DRBG_CSPRNG_OK;
}

void chacha_drbg_csprng_rekey(chacha_drbg_t* rng, const uint8_t extra[32]) {
    if (!rng || !extra) return;
    uint8_t tmp[32];
    chacha_drbg_csprng_bytes(rng, tmp, 32);
    for (int i = 0; i < 32; ++i) rng->key[i] ^= extra[i];
}
