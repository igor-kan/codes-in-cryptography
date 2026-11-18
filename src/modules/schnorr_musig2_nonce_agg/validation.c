#include "interface.h"

schnorr_musig2_nonce_agg_err_t schnorr_musig2_nonce_agg_validate_len(size_t n) {
    if (n == 0) {
        return SCHNORR_MUSIG2_NONCE_AGG_ERR_INVALID;
    }
    return SCHNORR_MUSIG2_NONCE_AGG_OK;
}
