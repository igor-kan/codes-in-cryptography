# Iterated Salted Key-Stretching Derivation Core (`pbkdf2_iterated_stretch_d56`)

> Category: **Key Derivation** | Language: **C11**

## Overview

Derives stretched 64-bit subkeys by XOR-accumulating sequential iterated PRF applications U_1 ^ ... ^ U_R seeded by password and salt.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(R) iterations` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Distinct iteration counts or distinct salts produce independent non-trivial keys.

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
