#ifndef HCHACHA20_XCHACHA_KDF_TYPES_H
#define HCHACHA20_XCHACHA_KDF_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint32_t words[8];
} hchacha_subkey_t;

#endif /* HCHACHA20_XCHACHA_KDF_TYPES_H */
