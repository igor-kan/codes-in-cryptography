#include "interface.h"

present80_spn_block_err_t present80_validate(const present80_key_t* ks) {
    return ks ? PRESENT80_SPN_BLOCK_OK : PRESENT80_SPN_BLOCK_ERR_NULL;
}
