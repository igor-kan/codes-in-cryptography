# MD5 512-Bit Merkle-Damgard Compression Stream Digest (`md5_stream_digest_d61`)

> Category: **Hash Functions** | Language: **C11**

## Overview

Streams arbitrary input through the MD5 little-endian padding rule and 64-step nonlinear compression function to produce the classic 128-bit digest.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N) 64-byte block compression with 64 ARX rounds per block` |
| **Space Complexity** | `O(1) 16-byte chaining state` |

## Mathematical & Safety Invariants

- Splitting an input across arbitrary update calls yields the same digest as a single call.

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
