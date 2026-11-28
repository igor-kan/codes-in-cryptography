# RIPEMD-160 Dual-Line Parallel Compression Digest (`ripemd160_digest_d61`)

> Category: **Hash Functions** | Language: **C11**

## Overview

Computes the RIPEMD-160 digest by running two independent five-round nonlinear lanes over each little-endian block and combining them into a single 160-bit chaining value.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N) 64-byte block compression with two 80-step parallel lanes` |
| **Space Complexity** | `O(1) 20-byte chaining state` |

## Mathematical & Safety Invariants

- Streaming updates reproduce the one-shot digest for every split boundary.

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
