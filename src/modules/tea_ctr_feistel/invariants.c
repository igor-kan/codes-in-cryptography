#include "interface.h"

tea_ctr_feistel_err_t tea_verify_involution(const tea_key_t* key, uint32_t v0, uint32_t v1) {
    if (!key) return TEA_CTR_FEISTEL_ERR_NULL;
    uint32_t v[2] = {v0, v1};
    tea_encrypt_block(key, v);
    tea_decrypt_block(key, v);
    return (v[0] == v0 && v[1] == v1) ? TEA_CTR_FEISTEL_OK : TEA_CTR_FEISTEL_ERR_INVARIANT;
}
