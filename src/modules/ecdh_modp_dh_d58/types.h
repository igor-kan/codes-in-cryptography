#ifndef ECDH_MODP_DH_D58_TYPES_H
#define ECDH_MODP_DH_D58_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint64_t pub_key;
    uint64_t shared_secret;
} dh_session_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} ecdh_modp_dh_d58_meta_t;

#endif /* ECDH_MODP_DH_D58_TYPES_H */
