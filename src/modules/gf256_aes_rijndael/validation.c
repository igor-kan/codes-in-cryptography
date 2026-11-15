#include "interface.h"
gf256_aes_rijndael_err_t gf256_aes_rijndael_validate_nz(uint8_t a) {
    return a != 0 ? GF256_AES_RIJNDAEL_OK : GF256_AES_RIJNDAEL_ERR_INVALID;
}
