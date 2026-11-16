# Base58 & Double-SHA256 Checksum Address Codec (Bitcoin Format) (`base58check_btc_codec`)

> Category: **Cryptographic Encoding** | Language: **C11**

## Overview

Implements Bitcoin-alphabet Base58 encoding/decoding with leading-zero '1' preservation and 4-byte SHA256(SHA256(payload)) Base58Check integrity verification.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N^2) big-radix base conversion` |
| **Space Complexity** | `O(N)` |

## Mathematical & Safety Invariants

- decode(encode(payload)) preserves leading zero bytes and exact byte values.
- Single-character tamper inside Base58Check encoded output is caught by checksum validation.

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
