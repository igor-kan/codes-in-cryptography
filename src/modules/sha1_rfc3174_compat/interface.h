#ifndef SHA1_RFC3174_COMPAT_INTERFACE_H
#define SHA1_RFC3174_COMPAT_INTERFACE_H

#include "types.h"
#include "errors.h"

void sha1_init(sha1_ctx_t* ctx);
void sha1_update(sha1_ctx_t* ctx, const uint8_t* data, size_t len);
void sha1_final(sha1_ctx_t* ctx, uint8_t digest[20]);
void sha1_oneshot(const uint8_t* data, size_t len, uint8_t digest[20]);
sha1_rfc3174_compat_err_t sha1_validate_ctx(const sha1_ctx_t* ctx);
sha1_rfc3174_compat_err_t sha1_batch_hash_mt(const uint8_t** inputs, const size_t* lens, uint8_t* out20, size_t n_items, size_t num_threads);
sha1_rfc3174_compat_err_t sha1_verify_rfc3174_vectors(void);

#endif /* SHA1_RFC3174_COMPAT_INTERFACE_H */
