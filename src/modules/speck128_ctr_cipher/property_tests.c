#include "interface.h"
#include <assert.h>

int main(void) {
    const uint64_t key[2] = {0xCAFEBABE12345678ULL, 0xDEADBEEF87654321ULL};
    speck128_rk_t rk;
    speck128_ctr_cipher_expand(key, &rk);
    assert(speck128_ctr_cipher_batch_check(&rk, 256) == SPECK128_CTR_CIPHER_OK);
    return 0;
}
