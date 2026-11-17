#include "interface.h"
#include <string.h>

static uint32_t rotl32(uint32_t x, int n) {
    return (n == 0) ? x : ((x << n) | (x >> (32 - n)));
}

static const uint32_t XOODOO_RC[12] = {
    0x00000058U, 0x00000038U, 0x000003c0U, 0x000000d0U,
    0x00000120U, 0x00000014U, 0x00000060U, 0x0000002cU,
    0x00000380U, 0x000000f0U, 0x000001a0U, 0x00000012U
};

void xoodoo_permute_12(xoodoo_state_t* st) {
    uint32_t* a = st->lanes;
    for (int r = 0; r < 12; ++r) {
        uint32_t p[4], e[4];
        for (int x = 0; x < 4; ++x) p[x] = a[x] ^ a[4 + x] ^ a[8 + x];
        for (int x = 0; x < 4; ++x) e[x] = rotl32(p[(x + 3) & 3], 5) ^ rotl32(p[(x + 3) & 3], 14);
        for (int i = 0; i < 12; ++i) a[i] ^= e[i & 3];

        uint32_t tmp[4];
        for (int x = 0; x < 4; ++x) tmp[x] = a[4 + ((x + 3) & 3)];
        for (int x = 0; x < 4; ++x) a[4 + x] = tmp[x];
        for (int x = 0; x < 4; ++x) a[8 + x] = rotl32(a[8 + x], 11);

        a[0] ^= XOODOO_RC[r];

        for (int x = 0; x < 4; ++x) {
            uint32_t b0 = (~a[4 + x]) & a[8 + x];
            uint32_t b1 = (~a[8 + x]) & a[x];
            uint32_t b2 = (~a[x]) & a[4 + x];
            a[x] ^= b0;
            a[4 + x] ^= b1;
            a[8 + x] ^= b2;
        }

        for (int x = 0; x < 4; ++x) a[4 + x] = rotl32(a[4 + x], 1);
        for (int x = 0; x < 4; ++x) tmp[x] = rotl32(a[8 + ((x + 2) & 3)], 8);
        for (int x = 0; x < 4; ++x) a[8 + x] = tmp[x];
    }
}

xoodyak_cyclist_perm_err_t xoodyak_duplex_tag(
    const uint8_t* key, size_t key_len, const uint8_t* msg, size_t msg_len, uint8_t out_tag[16]
) {
    xoodyak_cyclist_perm_err_t err = xoodyak_validate_key(key, key_len);
    if (err != XOODYAK_CYCLIST_PERM_OK || !out_tag || (msg_len > 0 && !msg)) return XOODYAK_CYCLIST_PERM_ERR_INVALID;
    xoodoo_state_t st;
    memset(&st, 0, sizeof(st));
    xoodoo_fast_xor_in(&st, key, key_len);
    st.lanes[4] ^= 0x02U;
    xoodoo_permute_12(&st);
    for (size_t off = 0; off < msg_len; off += 16) {
        size_t chunk = (msg_len - off < 16) ? (msg_len - off) : 16;
        xoodoo_fast_xor_in(&st, msg + off, chunk);
        ((uint8_t*)st.lanes)[chunk] ^= 0x01U;
        st.lanes[11] ^= 0x03000000U;
        xoodoo_permute_12(&st);
    }
    memcpy(out_tag, st.lanes, 16);
    return XOODYAK_CYCLIST_PERM_OK;
}
