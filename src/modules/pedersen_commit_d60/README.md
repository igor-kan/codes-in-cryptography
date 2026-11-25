# Homomorphic Pedersen Commitment Mod Safe Prime P (`pedersen_commit_d60`)

> Category: **Zero-Knowledge Commitments** | Language: **C11**

## Overview

Computes hiding and binding commitments C(v, r) = g^v * h^r mod p allowing algebraic sum verification C(v1+v2, r1+r2) == C(v1,r1)*C(v2,r2) mod p.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(log P) group modular exponentiation` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Commit(v1, r1) * Commit(v2, r2) mod p equals Commit(v1+v2 mod q, r1+r2 mod q).

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
