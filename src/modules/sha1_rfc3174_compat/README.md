# RFC 3174 SHA-1 160-Bit Compatibility Digest Engine (`sha1_rfc3174_compat`)

> Category: **Cryptographic Hash Functions** | Language: **C11**

## Overview

Implements complete RFC 3174 SHA-1 compression (80 rounds across four 20-round boolean mixing schedules) for legacy protocol verification and interoperability testing.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N)` |
| **Space Complexity** | `O(1) stack context` |

## Mathematical & Safety Invariants

- Matches RFC 3174 / FIPS 180-4 test vectors for empty string, 'abc', and 56-byte multi-block inputs.
- Incremental multi-chunk update digests match single-call one-shot digests identically.

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
