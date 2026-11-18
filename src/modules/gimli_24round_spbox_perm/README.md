# Gimli 384-Bit 24-Round SP-Box Cryptographic Permutation (`gimli_24round_spbox_perm`)

> Category: **Cryptographic Permutations** | Language: **C11**

## Overview

Executes Bernstein et al.'s 384-bit Gimli permutation across 24 rounds of non-linear 96-bit SP-boxes, linear column swaps, and round constant injection.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(24) 3x4 word-column SP-box rounds with small/big swaps` |
| **Space Complexity** | `O(1) 48-byte state` |

## Mathematical & Safety Invariants

- Bijective over 384-bit states and produces full-state diffusion within 24 rounds.

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
