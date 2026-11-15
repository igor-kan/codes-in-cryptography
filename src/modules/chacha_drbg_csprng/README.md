# ChaCha20 Fast-Key-Erasure Deterministic Random Bit Generator (`chacha_drbg_csprng`)

> Category: **CSPRNG** | Language: **C11**

## Overview

Implements DJB's fast-key-erasure CSPRNG backed by ChaCha20 20-round quarter-round permutations, automatically rotating the internal 256-bit seed key on every generation call for backtracking resistance.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N)` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Fast-key-erasure immediately overwrites the 256-bit state key after each block request.
- Identical seed inputs produce reproducible deterministic byte streams.

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
