#include "interface.h"
#include <assert.h>

int main(void) {
    assert(present80_verify_vector() == PRESENT80_SPN_BLOCK_OK);
    present80_key_t ks;
    present80_key_init(&ks, 0x0123456789ABCDEFULL, 0xAAAAU);
    uint64_t pt = 0xDEADCAFEBABEBEEFULL;
    uint64_t ct = present80_encrypt(&ks, pt);
    assert(ct != pt);
    assert(present80_decrypt(&ks, ct) == pt);
    return 0;
}
