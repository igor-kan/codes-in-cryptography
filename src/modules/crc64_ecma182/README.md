# CRC-64-ECMA-182 Bitwise & 256-Table Integrity Checksum (`crc64_ecma182`)

> Category: **Error Detection** | Language: **C11**

## Overview

Implements standard MSB-first ECMA-182 64-bit cyclic redundancy check (polynomial 0x42F0E1EBA9EA3693) both in branchless tableless form and cached 256-entry lookup-table fast path.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N)` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Table-driven fast path produces bitwise identical checksums to polynomial division.
- Matches standard ECMA-182 test vector 0x6C40DF5F0B497347 for ASCII '123456789'.

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
