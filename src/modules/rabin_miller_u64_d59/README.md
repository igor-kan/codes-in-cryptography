# Deterministic 64-Bit Miller-Rabin Primality Prover (`rabin_miller_u64_d59`)

> Category: **Public-Key Primitives** | Language: **C11**

## Overview

Proves 64-bit primality deterministically via fixed witness bases {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37} and 128-bit modular squaring.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(K * log^3 N) deterministic bases` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Rejects Carmichael numbers (561, 1105, 1729) while accepting true primes.

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
