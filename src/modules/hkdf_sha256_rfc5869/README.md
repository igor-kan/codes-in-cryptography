# RFC 5869 HMAC-SHA256 Extract-and-Expand Key Derivation (HKDF) (`hkdf_sha256_rfc5869`)

> Category: **Key Derivation Functions** | Language: **C11**

## Overview

Implements complete RFC 5869 HKDF Extract (PRK = HMAC(salt, IKM)) and Expand (T(i) chaining with info + counter byte) over standalone FIPS 180-4 SHA-256 and RFC 2104 HMAC.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(L / 32 * SHA256_block)` |
| **Space Complexity** | `O(1) stack state` |

## Mathematical & Safety Invariants

- Exact match against RFC 5869 Appendix A.1 official test vectors.
- Expand rejects requested okm_len > 255 * 32 bytes with ERR_BOUNDS.
- Constant-time equality check compares derived output keys without secret-dependent branching.

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
