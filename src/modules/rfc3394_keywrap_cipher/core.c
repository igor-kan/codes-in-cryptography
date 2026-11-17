#include "interface.h"

rfc3394_keywrap_cipher_err_t rfc3394_wrap(kek128_t kek, const uint64_t* pt_blocks, size_t n_blocks, uint64_t* out_ct) {
    if (!pt_blocks || !out_ct) return RFC3394_KEYWRAP_CIPHER_ERR_NULL;
    rfc3394_keywrap_cipher_err_t err = rfc3394_validate_n(n_blocks);
    if (err != RFC3394_KEYWRAP_CIPHER_OK) return err;
    uint64_t A = RFC3394_DEFAULT_IV;
    for (size_t i = 0; i < n_blocks; ++i) out_ct[i + 1] = pt_blocks[i];
    for (size_t j = 0; j < 6; ++j) {
        for (size_t i = 1; i <= n_blocks; ++i) {
            uint64_t b0 = A, b1 = out_ct[i];
            fast_speck128_pair(kek, &b0, &b1, false);
            uint64_t t = (uint64_t)(n_blocks * j + i);
            A = b0 ^ t;
            out_ct[i] = b1;
        }
    }
    out_ct[0] = A;
    return RFC3394_KEYWRAP_CIPHER_OK;
}

rfc3394_keywrap_cipher_err_t rfc3394_unwrap(kek128_t kek, const uint64_t* ct_blocks, size_t n_blocks, uint64_t* out_pt) {
    if (!ct_blocks || !out_pt) return RFC3394_KEYWRAP_CIPHER_ERR_NULL;
    rfc3394_keywrap_cipher_err_t err = rfc3394_validate_n(n_blocks);
    if (err != RFC3394_KEYWRAP_CIPHER_OK) return err;
    uint64_t A = ct_blocks[0];
    for (size_t i = 0; i < n_blocks; ++i) out_pt[i] = ct_blocks[i + 1];
    for (int j = 5; j >= 0; --j) {
        for (size_t i = n_blocks; i >= 1; --i) {
            uint64_t t = (uint64_t)(n_blocks * (size_t)j + i);
            uint64_t b0 = A ^ t, b1 = out_pt[i - 1];
            fast_speck128_pair(kek, &b0, &b1, true);
            A = b0;
            out_pt[i - 1] = b1;
        }
    }
    if (A != RFC3394_DEFAULT_IV) return RFC3394_KEYWRAP_CIPHER_ERR_INVARIANT;
    return RFC3394_KEYWRAP_CIPHER_OK;
}
