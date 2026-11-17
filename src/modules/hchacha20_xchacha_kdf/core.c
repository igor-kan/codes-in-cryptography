#include "interface.h"

static uint32_t load32_le(const uint8_t* p) {
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

static void store32_le(uint8_t* p, uint32_t v) {
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8); p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}

hchacha20_xchacha_kdf_err_t hchacha20_derive(const uint8_t key[32], const uint8_t nonce16[16], uint8_t out_subkey[32]) {
    hchacha20_xchacha_kdf_err_t err = hchacha20_validate_ptrs(key, nonce16, out_subkey);
    if (err != HCHACHA20_XCHACHA_KDF_OK) return err;
    uint32_t s[16] = {0x61707865U, 0x3320646eU, 0x79622d32U, 0x6b206574U};
    for (int i = 0; i < 8; ++i) s[4 + i] = load32_le(key + 4 * i);
    for (int i = 0; i < 4; ++i) s[12 + i] = load32_le(nonce16 + 4 * i);
    for (int i = 0; i < 10; ++i) {
        hchacha20_fast_qr(s, 0, 4,  8, 12);
        hchacha20_fast_qr(s, 1, 5,  9, 13);
        hchacha20_fast_qr(s, 2, 6, 10, 14);
        hchacha20_fast_qr(s, 3, 7, 11, 15);
        hchacha20_fast_qr(s, 0, 5, 10, 15);
        hchacha20_fast_qr(s, 1, 6, 11, 12);
        hchacha20_fast_qr(s, 2, 7,  8, 13);
        hchacha20_fast_qr(s, 3, 4,  9, 14);
    }
    for (int i = 0; i < 4; ++i) store32_le(out_subkey + 4 * i, s[i]);
    for (int i = 0; i < 4; ++i) store32_le(out_subkey + 16 + 4 * i, s[12 + i]);
    return HCHACHA20_XCHACHA_KDF_OK;
}
