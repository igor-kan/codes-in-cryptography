# RFC 3394 Authenticated Key Wrap Construction (SPN Block Core) (`rfc3394_keywrap_cipher`)

> Category: **Key Wrapping & Integrity** | Language: **C11**

## Overview

Implements RFC 3394 6-round Feistel key wrapping and unwrapping with the 0xA6A6A6A6A6A6A6A6 integrity check constant backed by an invertible keyed block cipher.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(6 * N) block rounds over N 64-bit key blocks` |
| **Space Complexity** | `O(N) 64-bit chunks` |

## Mathematical & Safety Invariants

- Unwrap rejects any ciphertext modified by a single bit via A != 0xA6A6A6A6A6A6A6A6ULL.
- unwrap(kek, wrap(kek, cek)) recovers exact Content Encryption Key.

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
