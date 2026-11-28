# Paillier Additively Homomorphic Public-Key Encryption (`paillier_additive_he_d61`)

> Category: **Public-Key Encryption** | Language: **C11**

## Overview

Encrypts messages as c = g^m * r^N mod N^2 so that componentwise ciphertext products decrypt to the sum of the plaintexts modulo N.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(log N) modular exponentiation over Z_{N^2}` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Decrypting the product of two ciphertexts yields the summed plaintext modulo N.

## Module Architecture

| File | Lifecycle Role |
| :--- | :--- |
| `types.h` | Stage 01 |
| `errors.h` | Stage 02 |
| `interface.h` | Stage 03 |
| `core.c` | Stage 04 |
| `validation.c` | Stage 05 |
| `fast_path.c` | Stage 06 |
| `concurrent.c` | Stage 07 |
| `invariants.c` | Stage 08 |
| `unit_tests.c` | Stage 09 |
| `property_tests.c` | Stage 10 |
| `benchmark.c` | Stage 11 |
| `README.md` | Stage 12 |

## Verification & Execution Example

```text
gcc -std=c11 -O2 -Wall -Wextra -Werror -pthread core.c validation.c fast_path.c concurrent.c invariants.c unit_tests.c -lm -o test_bin && ./test_bin
```

---
© 2026 Igor Kan
