#include "interface.h"

tea_ctr_feistel_err_t tea_validate_key(const tea_key_t* key) {
    if (!key) return TEA_CTR_FEISTEL_ERR_NULL;
    if ((key->k[0] | key->k[1] | key->k[2] | key->k[3]) == 0U) return TEA_CTR_FEISTEL_ERR_INVALID;
    return TEA_CTR_FEISTEL_OK;
}
