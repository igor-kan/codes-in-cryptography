/**
 * @file errors.c
 * @brief Rich diagnostic error reporting for Zero-Knowledge Inner Product Argument Verification.
 * Module: bulletproofs_inner_product
 */

typedef enum bulletproofs_inner_product_error_code {
    BULLETPROOFS_INNER_PRODUCT_STATUS_OK = 0,
    BULLETPROOFS_INNER_PRODUCT_ERR_NULL_PTR = -20,
    BULLETPROOFS_INNER_PRODUCT_ERR_OUT_OF_BOUNDS = -21,
    BULLETPROOFS_INNER_PRODUCT_ERR_DIVERGENCE = -22
} bulletproofs_inner_product_error_code_t;

const char* bulletproofs_inner_product_error_message(bulletproofs_inner_product_error_code_t code) {
    switch (code) {
        case BULLETPROOFS_INNER_PRODUCT_STATUS_OK: return "Operational success";
        case BULLETPROOFS_INNER_PRODUCT_ERR_NULL_PTR: return "Null pointer argument";
        case BULLETPROOFS_INNER_PRODUCT_ERR_OUT_OF_BOUNDS: return "Buffer boundary exceeded";
        case BULLETPROOFS_INNER_PRODUCT_ERR_DIVERGENCE: return "Numerical divergence detected";
        default: return "Unspecified error code";
    }
}
