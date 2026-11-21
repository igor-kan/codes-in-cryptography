#include "interface.h"
#include <math.h>
#include <string.h>

static int mod257(int v) {
    int r = v % 257;
    return r < 0 ? r + 257 : r;
}

static int pow257(int base, int exp) {
    int res = 1;
    int b = mod257(base);
    while (exp > 0) {
        if (exp & 1) res = (res * b) % 257;
        b = (b * b) % 257;
        exp >>= 1;
    }
    return res;
}

int gf257_eval_poly(const int *coeffs, int k, int x) {
    int acc = 0;
    for (int i = k - 1; i >= 0; --i) {
        acc = (acc * mod257(x) + mod257(coeffs[i])) % 257;
    }
    return acc;
}

int gf257_reconstruct_secret(const gf257_share_t *shares, int k) {
    int secret = 0;
    for (int i = 0; i < k; ++i) {
        int num = 1;
        int den = 1;
        for (int j = 0; j < k; ++j) {
            if (i == j) continue;
            num = (num * mod257(-shares[j].x)) % 257;
            den = (den * mod257(shares[i].x - shares[j].x)) % 257;
        }
        int inv_den = pow257(den, 255);
        int li = (num * inv_den) % 257;
        secret = (secret + shares[i].y * li) % 257;
    }
    return secret;
}
