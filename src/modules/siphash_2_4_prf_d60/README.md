# SipHash-2-4 Keyed 64-Bit Pseudorandom Function (`siphash_2_4_prf_d60`)

> Category: **Symmetric MAC / PRF** | Language: **C11**

## Overview

Implements Aumasson-Bernstein SipHash-2-4 using a 128-bit key and ARX SipRound transformations resistant to hash-flooding attacks.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N) 8-byte compression rounds with 4 finalization rounds` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Reproduces reference SipHash-2-4 test vector output for 15-byte sequential payload.

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
