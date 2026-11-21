# GF(2^8) Rijndael Field Multiply & Fermat Inverse (`gf256_aes_mul_inv_d56`)

> Category: **Finite Field Arithmetic** | Language: **C11**

## Overview

Computes multiplication modulo x^8 + x^4 + x^3 + x + 1 (0x11B) and multiplicative inverses via a^254 constant-exponentiation without lookup tables.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1) constant-step bit arithmetic` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Every non-zero byte a satisfies gf256_mul(a, gf256_inv(a)) == 1.

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
