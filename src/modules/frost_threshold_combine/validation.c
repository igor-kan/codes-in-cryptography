#include "interface.h"

frost_threshold_combine_err_t validate_signer_ids(const uint64_t* ids, size_t t) {
    if (!ids || t == 0) return FROST_THRESHOLD_COMBINE_ERR_INVALID;
    for (size_t i = 0; i < t; ++i) {
        if (ids[i] == 0) return FROST_THRESHOLD_COMBINE_ERR_INVALID;
        for (size_t j = i + 1; j < t; ++j) {
            if (ids[i] == ids[j]) return FROST_THRESHOLD_COMBINE_ERR_INVALID;
        }
    }
    return FROST_THRESHOLD_COMBINE_OK;
}
