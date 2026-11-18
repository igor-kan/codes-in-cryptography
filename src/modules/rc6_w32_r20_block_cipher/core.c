#include "interface.h"
#include <math.h>
#include <string.h>

static uint32_t rotl32(uint32_t x, uint32_t r) { r &= 31U; return (x << r) | (x >> ((32U - r) & 31U)); }
static uint32_t rotr32(uint32_t x, uint32_t r) { r &= 31U; return (x >> r) | (x << ((32U - r) & 31U)); }
void rc6_key_setup(rc6_ctx_t* ctx, const uint32_t key[4]) {
    uint32_t L[4] = {key[0], key[1], key[2], key[3]};
    ctx->S[0] = 0xB7E15163U;
    for (int i = 1; i < 44; ++i) ctx->S[i] = ctx->S[i - 1] + 0x9E3779B9U;
    uint32_t A = 0, B = 0, i = 0, j = 0;
    for (int s = 0; s < 132; ++s) {
        A = ctx->S[i] = rotl32(ctx->S[i] + A + B, 3);
        B = L[j] = rotl32(L[j] + A + B, A + B);
        i = (i + 1) % 44;
        j = (j + 1) & 3U;
    }
}
void rc6_encrypt_block(const rc6_ctx_t* ctx, const uint32_t pt[4], uint32_t ct[4]) {
    uint32_t A = pt[0], B = pt[1] + ctx->S[0], C = pt[2], D = pt[3] + ctx->S[1];
    for (int r = 1; r <= 20; ++r) {
        uint32_t t = rotl32(B * (2U * B + 1U), 5);
        uint32_t u = rotl32(D * (2U * D + 1U), 5);
        A = rotl32(A ^ t, u) + ctx->S[2 * r];
        C = rotl32(C ^ u, t) + ctx->S[2 * r + 1];
        uint32_t tmp = A; A = B; B = C; C = D; D = tmp;
    }
    A += ctx->S[42]; C += ctx->S[43];
    ct[0] = A; ct[1] = B; ct[2] = C; ct[3] = D;
}
void rc6_decrypt_block(const rc6_ctx_t* ctx, const uint32_t ct[4], uint32_t pt[4]) {
    uint32_t A = ct[0] - ctx->S[42], B = ct[1], C = ct[2] - ctx->S[43], D = ct[3];
    for (int r = 20; r >= 1; --r) {
        uint32_t tmp = D; D = C; C = B; B = A; A = tmp;
        uint32_t u = rotl32(D * (2U * D + 1U), 5);
        uint32_t t = rotl32(B * (2U * B + 1U), 5);
        C = rotr32(C - ctx->S[2 * r + 1], t) ^ u;
        A = rotr32(A - ctx->S[2 * r], u) ^ t;
    }
    D -= ctx->S[1]; B -= ctx->S[0];
    pt[0] = A; pt[1] = B; pt[2] = C; pt[3] = D;
}
