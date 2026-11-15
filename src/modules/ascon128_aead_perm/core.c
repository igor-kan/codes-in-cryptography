#include "interface.h"
#include <string.h>

static inline uint64_t ror64(uint64_t x, int n) { return (x >> n) | (x << (64 - n)); }
static uint64_t load64be(const uint8_t* p) {
    uint64_t r = 0;
    for (int i = 0; i < 8; ++i) r = (r << 8) | p[i];
    return r;
}
static void store64be(uint8_t* p, uint64_t v) {
    for (int i = 0; i < 8; ++i) p[i] = (uint8_t)(v >> (56 - 8 * i));
}

void ascon128_aead_perm_permute(ascon_state_t* s, int rounds) {
    static const uint64_t RC[12] = {0xf0,0xe1,0xd2,0xc3,0xb4,0xa5,0x96,0x87,0x78,0x69,0x5a,0x4b};
    int start = 12 - rounds;
    for (int r = start; r < 12; ++r) {
        s->x[2] ^= RC[r];
        s->x[0] ^= s->x[4]; s->x[4] ^= s->x[3]; s->x[2] ^= s->x[1];
        uint64_t t[5];
        for (int i = 0; i < 5; ++i) t[i] = (~s->x[i]) & s->x[(i + 1) % 5];
        for (int i = 0; i < 5; ++i) s->x[i] ^= t[(i + 1) % 5];
        s->x[1] ^= s->x[0]; s->x[0] ^= s->x[4]; s->x[3] ^= s->x[2]; s->x[2] = ~s->x[2];
        s->x[0] ^= ror64(s->x[0], 19) ^ ror64(s->x[0], 28);
        s->x[1] ^= ror64(s->x[1], 61) ^ ror64(s->x[1], 39);
        s->x[2] ^= ror64(s->x[2], 1)  ^ ror64(s->x[2], 6);
        s->x[3] ^= ror64(s->x[3], 10) ^ ror64(s->x[3], 17);
        s->x[4] ^= ror64(s->x[4], 7)  ^ ror64(s->x[4], 41);
    }
}

int ascon128_aead_perm_ct_eq16(const uint8_t a[16], const uint8_t b[16]) {
    uint8_t d = 0;
    for (int i = 0; i < 16; ++i) d |= (uint8_t)(a[i] ^ b[i]);
    return d == 0;
}

static void ascon_init(ascon_state_t* s, const uint8_t key[16], const uint8_t nonce[16]) {
    uint64_t k0 = load64be(key), k1 = load64be(key + 8);
    s->x[0] = 0x80400c0600000000ULL;
    s->x[1] = k0; s->x[2] = k1;
    s->x[3] = load64be(nonce); s->x[4] = load64be(nonce + 8);
    ascon128_aead_perm_permute(s, 12);
    s->x[3] ^= k0; s->x[4] ^= k1;
}

ascon128_aead_perm_err_t ascon128_aead_perm_encrypt(
    const uint8_t key[16], const uint8_t nonce[16],
    const uint8_t* ad, size_t ad_len,
    const uint8_t* pt, size_t pt_len, uint8_t* ct, uint8_t tag[16]
) {
    if (!key || !nonce || !tag || (pt_len > 0 && (!pt || !ct))) return ASCON128_AEAD_PERM_ERR_NULL;
    ascon_state_t s;
    ascon_init(&s, key, nonce);
    if (ad_len > 0 && ad) {
        size_t i = 0;
        while (i + 8 <= ad_len) { s.x[0] ^= load64be(ad + i); ascon128_aead_perm_permute(&s, 6); i += 8; }
        uint8_t pad[8] = {0}; size_t rem = ad_len - i;
        if (rem) memcpy(pad, ad + i, rem);
        pad[rem] = 0x80U;
        s.x[0] ^= load64be(pad);
        ascon128_aead_perm_permute(&s, 6);
    }
    s.x[4] ^= 1ULL;
    size_t i = 0;
    while (i + 8 <= pt_len) {
        s.x[0] ^= load64be(pt + i);
        store64be(ct + i, s.x[0]);
        ascon128_aead_perm_permute(&s, 6);
        i += 8;
    }
    uint8_t pad[8] = {0}, outblk[8] = {0};
    size_t rem = pt_len - i;
    if (rem) memcpy(pad, pt + i, rem);
    pad[rem] = 0x80U;
    s.x[0] ^= load64be(pad);
    store64be(outblk, s.x[0]);
    if (rem) memcpy(ct + i, outblk, rem);
    uint64_t k0 = load64be(key), k1 = load64be(key + 8);
    s.x[1] ^= k0; s.x[2] ^= k1;
    ascon128_aead_perm_permute(&s, 12);
    store64be(tag, s.x[3] ^ k0);
    store64be(tag + 8, s.x[4] ^ k1);
    return ASCON128_AEAD_PERM_OK;
}

ascon128_aead_perm_err_t ascon128_aead_perm_decrypt(
    const uint8_t key[16], const uint8_t nonce[16],
    const uint8_t* ad, size_t ad_len,
    const uint8_t* ct, size_t ct_len, const uint8_t tag[16], uint8_t* pt
) {
    if (!key || !nonce || !tag || (ct_len > 0 && (!ct || !pt))) return ASCON128_AEAD_PERM_ERR_NULL;
    ascon_state_t s;
    ascon_init(&s, key, nonce);
    if (ad_len > 0 && ad) {
        size_t i = 0;
        while (i + 8 <= ad_len) { s.x[0] ^= load64be(ad + i); ascon128_aead_perm_permute(&s, 6); i += 8; }
        uint8_t pad[8] = {0}; size_t rem = ad_len - i;
        if (rem) memcpy(pad, ad + i, rem);
        pad[rem] = 0x80U;
        s.x[0] ^= load64be(pad);
        ascon128_aead_perm_permute(&s, 6);
    }
    s.x[4] ^= 1ULL;
    size_t i = 0;
    while (i + 8 <= ct_len) {
        uint64_t c = load64be(ct + i);
        store64be(pt + i, s.x[0] ^ c);
        s.x[0] = c;
        ascon128_aead_perm_permute(&s, 6);
        i += 8;
    }
    uint8_t blk[8] = {0}, pblk[8] = {0};
    store64be(blk, s.x[0]);
    size_t rem = ct_len - i;
    for (size_t k = 0; k < rem; ++k) {
        pblk[k] = (uint8_t)(blk[k] ^ ct[i + k]);
        blk[k] = ct[i + k];
    }
    blk[rem] ^= 0x80U;
    s.x[0] = load64be(blk);
    if (rem) memcpy(pt + i, pblk, rem);
    uint64_t k0 = load64be(key), k1 = load64be(key + 8);
    s.x[1] ^= k0; s.x[2] ^= k1;
    ascon128_aead_perm_permute(&s, 12);
    uint8_t calc_tag[16];
    store64be(calc_tag, s.x[3] ^ k0);
    store64be(calc_tag + 8, s.x[4] ^ k1);
    if (!ascon128_aead_perm_ct_eq16(calc_tag, tag)) {
        if (ct_len > 0) memset(pt, 0, ct_len);
        return ASCON128_AEAD_PERM_ERR_INVALID;
    }
    return ASCON128_AEAD_PERM_OK;
}
