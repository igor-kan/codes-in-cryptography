#include "interface.h"
#include <math.h>
#include <string.h>

static uint32_t rc5_rotl(uint32_t x, uint32_t n) {
    n &= 31U;
    return (x << n) | (x >> ((32U - n) & 31U));
}
static uint32_t rc5_rotr(uint32_t x, uint32_t n) {
    n &= 31U;
    return (x >> n) | (x << ((32U - n) & 31U));
}
void rc5_setup_d61(rc5_ctx_d61_t* ctx, const uint8_t key[16]) {
    uint32_t l[4] = {0U, 0U, 0U, 0U};
    for (int i = 15; i >= 0; --i) l[i / 4] = (l[i / 4] << 8) | key[i];
    ctx->s[0] = 0xb7e15163U;
    for (int i = 1; i < RC5_SUBKEYS; ++i) ctx->s[i] = ctx->s[i - 1] + 0x9e3779b9U;
    uint32_t a = 0U, b = 0U;
    int i = 0, j = 0;
    for (int k = 0; k < 3 * RC5_SUBKEYS; ++k) {
        a = ctx->s[i] = rc5_rotl(ctx->s[i] + a + b, 3U);
        b = l[j] = rc5_rotl(l[j] + a + b, a + b);
        i = (i + 1) % RC5_SUBKEYS;
        j = (j + 1) % 4;
    }
}
void rc5_encrypt_d61(const rc5_ctx_d61_t* ctx, const uint32_t in[2], uint32_t out[2]) {
    uint32_t a = in[0] + ctx->s[0];
    uint32_t b = in[1] + ctx->s[1];
    for (int r = 1; r <= RC5_ROUNDS; ++r) {
        a = rc5_rotl(a ^ b, b) + ctx->s[2 * r];
        b = rc5_rotl(b ^ a, a) + ctx->s[2 * r + 1];
    }
    out[0] = a;
    out[1] = b;
}
void rc5_decrypt_d61(const rc5_ctx_d61_t* ctx, const uint32_t in[2], uint32_t out[2]) {
    uint32_t a = in[0];
    uint32_t b = in[1];
    for (int r = RC5_ROUNDS; r >= 1; --r) {
        b = rc5_rotr(b - ctx->s[2 * r + 1], a) ^ a;
        a = rc5_rotr(a - ctx->s[2 * r], b) ^ b;
    }
    out[0] = a - ctx->s[0];
    out[1] = b - ctx->s[1];
}
