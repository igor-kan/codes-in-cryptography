#include "interface.h"

size_t b58_estimate_encoded_cap(size_t payload_len) {
    if (payload_len > (SIZE_MAX / 2U) - 16U) return 0U;
    return ((payload_len + 4U) * 138U) / 100U + 4U;
}

size_t b58_count_leading_zeros(const uint8_t* data, size_t len) {
    if (!data) return 0U;
    size_t z = 0U;
    while (z < len && data[z] == 0U) ++z;
    return z;
}
