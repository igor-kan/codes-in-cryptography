#ifndef GF256_INV_AFFINE_SBOX_ERRORS_H
#define GF256_INV_AFFINE_SBOX_ERRORS_H

typedef enum gf256_inv_affine_sbox_err {
    GF256_INV_AFFINE_SBOX_OK = 0,
    GF256_INV_AFFINE_SBOX_ERR_NULL = -1,
    GF256_INV_AFFINE_SBOX_ERR_BOUNDS = -2,
    GF256_INV_AFFINE_SBOX_ERR_INVALID = -3,
    GF256_INV_AFFINE_SBOX_ERR_OVERFLOW = -4,
    GF256_INV_AFFINE_SBOX_ERR_INVARIANT = -5
} gf256_inv_affine_sbox_err_t;



static inline const char* gf256_inv_affine_sbox_err_str(gf256_inv_affine_sbox_err_t err) {
    switch (err) {
        case GF256_INV_AFFINE_SBOX_OK: return "ok";
        case GF256_INV_AFFINE_SBOX_ERR_NULL: return "null pointer supplied";
        case GF256_INV_AFFINE_SBOX_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case GF256_INV_AFFINE_SBOX_ERR_INVALID: return "domain precondition violated";
        case GF256_INV_AFFINE_SBOX_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case GF256_INV_AFFINE_SBOX_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* GF256_INV_AFFINE_SBOX_ERRORS_H */
