/**
 * @file errors.c
 * @brief Rich diagnostic error reporting for Cryptographic Merkle Sum Tree for Proof of Solvency.
 * Module: merkle_sum_tree
 */

typedef enum merkle_sum_tree_error_code {
    MERKLE_SUM_TREE_STATUS_OK = 0,
    MERKLE_SUM_TREE_ERR_NULL_PTR = -20,
    MERKLE_SUM_TREE_ERR_OUT_OF_BOUNDS = -21,
    MERKLE_SUM_TREE_ERR_DIVERGENCE = -22
} merkle_sum_tree_error_code_t;

const char* merkle_sum_tree_error_message(merkle_sum_tree_error_code_t code) {
    switch (code) {
        case MERKLE_SUM_TREE_STATUS_OK: return "Operational success";
        case MERKLE_SUM_TREE_ERR_NULL_PTR: return "Null pointer argument";
        case MERKLE_SUM_TREE_ERR_OUT_OF_BOUNDS: return "Buffer boundary exceeded";
        case MERKLE_SUM_TREE_ERR_DIVERGENCE: return "Numerical divergence detected";
        default: return "Unspecified error code";
    }
}
