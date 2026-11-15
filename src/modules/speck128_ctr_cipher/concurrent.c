#include "interface.h"
speck128_ctr_cipher_err_t speck128_ctr_cipher_batch_check(const speck128_rk_t* rk, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        uint64_t pt[2] = {i, i * 31ULL}, ct[2], rec[2];
        speck128_ctr_cipher_enc_block(rk, pt, ct);
        speck128_ctr_cipher_dec_block(rk, ct, rec);
        if (rec[0] != pt[0] || rec[1] != pt[1]) return SPECK128_CTR_CIPHER_ERR_INVARIANT;
    }
    return SPECK128_CTR_CIPHER_OK;
}
