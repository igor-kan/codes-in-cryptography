# Balanced 4-Round Feistel 64-Bit PRP (`feistel_balanced_prp_d56`)

> Category: **Block Permutations** | Language: **C11**

## Overview

Constructs a strictly invertible 64-bit pseudorandom permutation using balanced 32-bit half swaps and key-dependent ARX round functions.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1) 4-round bijection` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Forward followed by reverse schedule restores original (L, R) exactly across every key.

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
