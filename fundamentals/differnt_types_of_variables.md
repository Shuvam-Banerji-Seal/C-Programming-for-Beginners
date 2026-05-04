# `differnt_types_of_variables.c`

> 64-bit system: int (4 bytes), float (4 bytes), char (1 byte)

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `fundamentals/differnt_types_of_variables.c` |
| **Type** | C source |
| **Module** | `fundamentals` |
| **Lines** | 51 total (46 code, 1 comments) |
| **Libraries** | `stdio.h` |
| **Topics** | Fundamentals |

## What It Does

Variable types in C: local, global, static, register, and `extern`. Explains scope, lifetime, linkage, and storage classes with practical examples.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (22 calls) to display output to the console
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
cd fundamentals

# Compile with GCC (debug build)
gcc differnt_types_of_variables.c -o differnt_types_of_variables -std=c11 -Wall -Wextra -g

# Run
./differnt_types_of_variables

# Compile with Clang
clang differnt_types_of_variables.c -o differnt_types_of_variables -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc differnt_types_of_variables.c -o differnt_types_of_variables -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
