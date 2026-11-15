# RFC 2104 HMAC-SHA256 & HKDF-Expand Keyed Hash PRF (`hmac_sha256_prf`)

> Category: **MAC & Key Derivation** | Language: **C11**

## Overview

Implements full RFC 2104 HMAC-SHA256 authentication code and RFC 5869 HKDF-Expand key derivation over an embedded FIPS 180-4 SHA-256 engine.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N)` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Matches RFC 4231 official Known-Answer Test vectors bit-for-bit.
- Keys longer than 64 bytes are pre-hashed via SHA-256 before XOR with ipad/opad.
- Constant-time 32-byte digest comparison avoids timing side-channels.

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
