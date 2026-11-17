#include "interface.h"

xoodyak_cyclist_perm_err_t xoodyak_validate_key(const uint8_t* key, size_t key_len) {
    if (!key) return XOODYAK_CYCLIST_PERM_ERR_NULL;
    if (key_len == 0 || key_len > 32) return XOODYAK_CYCLIST_PERM_ERR_BOUNDS;
    return XOODYAK_CYCLIST_PERM_OK;
}
