# `sizeof_demo.c`

> sizeof_demo.c
Demonstrates the sizeof operator

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `02-variables-and-types/sizeof_demo.c` |
| **Type** | C source |
| **Module** | `02-variables-and-types` |
| **Lines** | 55 total (40 code, 4 comments) |
| **Libraries** | `stdio.h` |
| **Topics** | Fundamentals |

## What It Does

The `sizeof` operator determines memory size of types and variables. Shows results for all primitive types, arrays, structs (with padding), and pointers on your specific platform.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (28 calls) to display output to the console
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
gcc sizeof_demo.c -o sizeof_demo -std=c11 -Wall -Wextra -g

# Run
./sizeof_demo

# Compile with Clang
clang sizeof_demo.c -o sizeof_demo -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc sizeof_demo.c -o sizeof_demo -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
