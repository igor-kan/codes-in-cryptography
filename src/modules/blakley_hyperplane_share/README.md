# 2-of-N Blakley Linear Hyperplane Intersection Secret Sharing (`blakley_hyperplane_share`)

> Category: **Threshold Secret Sharing** | Language: **C11**

## Overview

Encodes a secret s in GF(p) as a point (s, y0) and distributes 2-of-N affine line shares a_i*x + b_i*y = c_i (mod p) so any two non-parallel shares recover s.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1) 2x2 modular linear system intersection mod prime P` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Any two distinct lines intersect at exact secret x-coordinate s mod p.

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
