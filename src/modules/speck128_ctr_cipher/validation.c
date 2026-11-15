#include "interface.h"
speck128_ctr_cipher_err_t speck128_ctr_cipher_validate(const speck128_rk_t* rk) {
    return rk ? SPECK128_CTR_CIPHER_OK : SPECK128_CTR_CIPHER_ERR_NULL;
}
