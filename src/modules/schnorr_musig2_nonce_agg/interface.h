#ifndef SCHNORR_MUSIG2_NONCE_AGG_INTERFACE_H
#define SCHNORR_MUSIG2_NONCE_AGG_INTERFACE_H

#include "types.h"
#include "errors.h"

uint64_t musig_pow_p(uint64_t base, uint64_t exp);
uint64_t musig_bind_coeff(const musig_nonce_t* nonces, size_t n, uint64_t msg);
uint64_t musig_agg_pub_nonce(const musig_nonce_t* nonces, size_t n, uint64_t b);

schnorr_musig2_nonce_agg_err_t schnorr_musig2_nonce_agg_validate_len(size_t n);
uint64_t schnorr_musig2_nonce_agg_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t schnorr_musig2_nonce_agg_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
schnorr_musig2_nonce_agg_err_t schnorr_musig2_nonce_agg_verify_guard(bool cond);

#endif /* SCHNORR_MUSIG2_NONCE_AGG_INTERFACE_H */
