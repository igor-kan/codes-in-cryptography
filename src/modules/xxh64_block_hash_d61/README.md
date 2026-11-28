# xxHash64 Striped 64-Bit Non-Cryptographic Block Hash (`xxh64_block_hash_d61`)

> Category: **Fast Hashing** | Language: **C11**

## Overview

Implements xxHash64 with four parallel lane accumulators, prime-multiplied merge rounds, and the final xor-shift avalanche mixer.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N) 32-byte stripe accumulation plus avalanche finalizer` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- The empty input hashes to 0xEF46DB3751D8E999 with seed zero.

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
