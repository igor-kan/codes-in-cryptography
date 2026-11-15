#include "interface.h"
speck128_ctr_cipher_err_t speck128_ctr_cipher_verify_kat(void) {
    // Official Speck-128/128 KAT (Beaulieu IACR 2013/404): Key=0f0e..08 0706..00, Pt=" made it equival" -> Ct=a65d985179783265 7860fedf5c570d18
    const uint64_t key[2] = {0x0706050403020100ULL, 0x0f0e0d0c0b0a0908ULL};
    const uint64_t pt[2] = {0x7469206564616d20ULL, 0x6c61766975716520ULL};
    const uint64_t exp_ct[2] = {0x7860fedf5c570d18ULL, 0xa65d985179783265ULL};
    speck128_rk_t rk;
    uint64_t ct[2], rec[2];
    speck128_ctr_cipher_expand(key, &rk);
    speck128_ctr_cipher_enc_block(&rk, pt, ct);
    speck128_ctr_cipher_dec_block(&rk, ct, rec);
    if (ct[0] != exp_ct[0] || ct[1] != exp_ct[1]) return SPECK128_CTR_CIPHER_ERR_INVARIANT;
    if (rec[0] != pt[0] || rec[1] != pt[1]) return SPECK128_CTR_CIPHER_ERR_INVARIANT;
    return SPECK128_CTR_CIPHER_OK;
}
