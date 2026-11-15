#include "interface.h"
#include <assert.h>

int main(void) {
    // Commutativity and distributivity across GF(2^8)
    for (int a = 0; a < 256; a += 7) {
        for (int b = 0; b < 256; b += 11) {
            uint8_t x = (uint8_t)a, y = (uint8_t)b;
            assert(gf256_aes_rijndael_mul(x, y) == gf256_aes_rijndael_mul(y, x));
            uint8_t c = (uint8_t)(x ^ y ^ 0x5A);
            assert(gf256_aes_rijndael_mul(x, (uint8_t)(y ^ c)) ==
                   (gf256_aes_rijndael_mul(x, y) ^ gf256_aes_rijndael_mul(x, c)));
        }
    }
    return 0;
}
