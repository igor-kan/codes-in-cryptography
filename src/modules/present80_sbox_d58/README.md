# SPN Bijective 4-Bit S-Box + Permutation Network (`present80_sbox_d58`)

> Category: **Block Cipher Components** | Language: **C11**

## Overview

Implements PRESENT's exact 4-bit nonlinear S-box S[x] and its exact inverse S^-1[x] paired with 64-bit bit-permutation inversion.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1) constant-step SPN round` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Applying forward S-box layer followed by inverse S-box recovers original 64-bit state cleanly.

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
