#include "interface.h"
#include <assert.h>

int main(void) {
    uint32_t key[4] = {1U, 2U, 3U, 4U};
    simon64_key_t ks;
    simon64_key_init(&ks, key);
    uint64_t buf[32], orig[32];
    for (size_t i = 0; i < 32; ++i) buf[i] = orig[i] = 0x11223344ULL + i;
    simon64_parallel_ctr(&ks, 0xCAFEBABEULL, buf, 32);
    simon64_parallel_ctr(&ks, 0xCAFEBABEULL, buf, 32);
    for (size_t i = 0; i < 32; ++i) assert(buf[i] == orig[i]);
    return 0;
}
