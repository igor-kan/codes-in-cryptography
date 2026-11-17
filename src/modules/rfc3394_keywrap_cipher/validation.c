#include "interface.h"

rfc3394_keywrap_cipher_err_t rfc3394_validate_n(size_t n_blocks) {
    if (n_blocks < 2 || n_blocks > 64) return RFC3394_KEYWRAP_CIPHER_ERR_BOUNDS;
    return RFC3394_KEYWRAP_CIPHER_OK;
}
