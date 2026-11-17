#include "interface.h"

present80_spn_block_err_t present80_verify_vector(void) {
    present80_key_t ks;
    present80_key_init(&ks, 0ULL, 0);
    uint64_t ct = present80_encrypt(&ks, 0ULL);
    uint64_t dec = present80_decrypt(&ks, ct);
    if (ct != 0x5579C1387B228445ULL || dec != 0ULL) return PRESENT80_SPN_BLOCK_ERR_INVARIANT;
    return PRESENT80_SPN_BLOCK_OK;
}
