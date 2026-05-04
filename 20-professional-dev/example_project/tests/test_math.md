# `test_math.c`

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `20-professional-dev/example_project/tests/test_math.c` |
| **Type** | C source |
| **Module** | `tests` |
| **Lines** | 34 total (26 code, 0 comments) |
| **Libraries** | `stdio.h`, `assert.h`, `math_utils.h` |
| **Topics** | Functions |

## What It Does

Unit test file for mathematical utilities. Demonstrates testing patterns in C using assertions and test harnesses. Shows how professional C projects organize and run tests.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (5 calls) to display output to the console
7. Returns 0 to indicate successful completion

## Key Code Patterns

```c
#include <stdio.h>
#include <assert.h>
#include <math_utils.h>

int main(void) {
    // ... program logic ...
    return 0;
}
```

## Libraries Used

- **`<stdio.h>`** — Standard I/O: `printf()`, `scanf()`, `fgets()`, `FILE` operations
- **`<assert.h>`** — Debugging: `assert()` macro for runtime invariants
- **`<math_utils.h>`** — Standard C library

## Functions

| Function | Returns | Parameters | Purpose |
|----------|---------|------------|---------|
| `test_add()` | `void` | `` | See implementation for details |
| `test_multiply()` | `void` | `` | See implementation for details |
| `test_factorial()` | `void` | `` | See implementation for details |

## Compilation

```bash
cd 20-professional-dev/example_project/tests

# Compile with GCC (debug build)
gcc test_math.c -o test_math -std=c11 -Wall -Wextra -g

# Run
./test_math

# Compile with Clang
clang test_math.c -o test_math -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc test_math.c -o test_math -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`
- **Library header:** `<assert.h>`
- **Library header:** `<math_utils.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
