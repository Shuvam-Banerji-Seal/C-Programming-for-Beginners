# `operators.c`

> operators.c
Comprehensive demonstration of all operators in C

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `02-variables-and-types/operators.c` |
| **Type** | C source |
| **Module** | `02-variables-and-types` |
| **Lines** | 79 total (56 code, 11 comments) |
| **Libraries** | `stdio.h` |
| **Topics** | Fundamentals |

## What It Does

C operators demonstrated in detail: arithmetic, relational, logical, bitwise, assignment, and the ternary operator. Shows precedence and common usage patterns.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (43 calls) to display output to the console
7. Returns 0 to indicate successful completion

## Key Code Patterns

```c
#include <stdio.h>

int main(void) {
    // ... program logic ...
    return 0;
}
```

## Libraries Used

- **`<stdio.h>`** — Standard I/O: `printf()`, `scanf()`, `fgets()`, `FILE` operations

## Compilation

```bash
cd 02-variables-and-types

# Compile with GCC (debug build)
gcc operators.c -o operators -std=c11 -Wall -Wextra -g

# Run
./operators

# Compile with Clang
clang operators.c -o operators -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc operators.c -o operators -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
