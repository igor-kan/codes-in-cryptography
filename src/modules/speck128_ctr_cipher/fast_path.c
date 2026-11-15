#include "interface.h"
void speck128_ctr_cipher_enc_ecb_fast(const speck128_rk_t* rk, const uint64_t* pt, uint64_t* ct, size_t nblocks) {
    for (size_t i = 0; i < nblocks; ++i) speck128_ctr_cipher_enc_block(rk, pt + 2*i, ct + 2*i);
}
