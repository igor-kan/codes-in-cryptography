#include "interface.h"
#include <assert.h>
#include <string.h>

int main(void) {
    uint8_t k[32] = {7}, n[64] = {0}, out[128];
    for (int i = 0; i < 4; ++i) n[16 * i] = (uint8_t)i;
    hchacha20_parallel_derive(k, n, 4, out);
    assert(memcmp(out, out + 32, 32) != 0);
    assert(memcmp(out + 32, out + 64, 32) != 0);
    return 0;
}
