# `data_types.c`

> 64-bit system: int (4 bytes), float (4 bytes), char (1 byte)

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `02-variables-and-types/data_types.c` |
| **Type** | C source |
| **Module** | `02-variables-and-types` |
| **Lines** | 51 total (46 code, 1 comments) |
| **Libraries** | `stdio.h` |
| **Topics** | Fundamentals |

## What It Does

C data types: `int`, `float`, `double`, `char`, their variants (`short`, `long`, `unsigned`), and the `sizeof` operator. Demonstrates type ranges, memory sizes, and format specifiers.

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
cd 02-variables-and-types

# Compile with GCC (debug build)
gcc data_types.c -o data_types -std=c11 -Wall -Wextra -g

# Run
./data_types

# Compile with Clang
clang data_types.c -o data_types -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc data_types.c -o data_types -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
