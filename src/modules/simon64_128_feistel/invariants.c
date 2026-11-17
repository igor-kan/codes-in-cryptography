#include "interface.h"

simon64_128_feistel_err_t simon64_verify_roundtrip(const uint32_t key[4], const uint32_t pt[2]) {
    simon64_key_t ks;
    simon64_key_init(&ks, key);
    uint32_t ct[2], rec[2];
    simon64_encrypt_block(&ks, pt, ct);
    simon64_decrypt_block(&ks, ct, rec);
    return (rec[0] == pt[0] && rec[1] == pt[1]) ? SIMON64_128_FEISTEL_OK : SIMON64_128_FEISTEL_ERR_INVARIANT;
}
