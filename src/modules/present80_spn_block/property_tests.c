#include "interface.h"
#include <assert.h>

int main(void) {
    present80_key_t ks;
    present80_key_init(&ks, 0xFFFFFFFFFFFFFFFFULL, 0xFFFFU);
    uint64_t buf[16], orig[16];
    for (size_t i = 0; i < 16; ++i) buf[i] = orig[i] = i * 97ULL + 5ULL;
    present80_parallel_encrypt(&ks, buf, 16);
    for (size_t i = 0; i < 16; ++i) assert(present80_decrypt(&ks, buf[i]) == orig[i]);
    return 0;
}
