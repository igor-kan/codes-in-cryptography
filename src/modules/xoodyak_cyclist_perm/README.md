# Xoodoo-384 Lightweight Permutation & Cyclist Duplex Sponge (`xoodyak_cyclist_perm`)

> Category: **Lightweight Cryptography** | Language: **C11**

## Overview

Implements the NIST lightweight cryptography finalist Xoodoo 384-bit (3x4 uint32_t) 12-round permutation (theta, rho_west, iota, chi, rho_east) and Cyclist-style keyed absorb/squeeze sponge mode.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1) 12-round 384-bit ARX state permutation` |
| **Space Complexity** | `48 bytes fixed permutation state` |

## Mathematical & Safety Invariants

- Permutation maps non-zero inputs deterministically with full 384-bit diffusion.
- Flipping 1 bit of input state flips multiple bits across all 3 planes.

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
