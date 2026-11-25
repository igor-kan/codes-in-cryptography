# Constant-Time AES-GCM GF(2^128) Polynomial Multiplier (`gf128_ghash_mul_d60`)

> Category: **Authenticated Encryption** | Language: **C11**

## Overview

Performs constant-time NIST SP 800-38D Galois field multiplication over 128-bit big-endian blocks without cache-timing lookup tables.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1) 128-step bit-slicing multiply in GF(2)[x]/(x^128+x^7+x^2+x+1)` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Satisfies distributivity X * (A ^ B) == (X * A) ^ (X * B).

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
