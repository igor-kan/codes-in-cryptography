#include "interface.h"

scrypt_salsa20_romix_err_t scrypt_validate_n(size_t N, size_t r) {
    if (r == 0 || r > 16 || N < 2 || (N & (N - 1)) != 0) return SCRYPT_SALSA20_ROMIX_ERR_INVALID;
    return SCRYPT_SALSA20_ROMIX_OK;
}
