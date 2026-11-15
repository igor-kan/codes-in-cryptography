# RFC 8018 PBKDF2-HMAC-SHA256 Password Key Derivation Function (`pbkdf2_hmac_kdf`)

> Category: **Key Derivation** | Language: **C11**

## Overview

Implements RFC 8018 Password-Based Key Derivation Function 2 (PBKDF2) using HMAC-SHA256 PRF with multi-block counter indexing and XOR chaining across iteration count c.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(c * dkLen)` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Matches RFC 6070 / RFC 7914 PBKDF2-HMAC-SHA256 Known-Answer Vectors.
- Iteration count c == 0 or zero dkLen are rejected cleanly.

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
