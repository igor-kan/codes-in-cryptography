#include "interface.h"

schnorr_musig2_nonce_agg_err_t schnorr_musig2_nonce_agg_verify_guard(bool cond) {
    if (!cond) {
        return SCHNORR_MUSIG2_NONCE_AGG_ERR_INVARIANT;
    }
    return SCHNORR_MUSIG2_NONCE_AGG_OK;
}
