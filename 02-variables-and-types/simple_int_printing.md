# `simple_int_printing.c`

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `02-variables-and-types/simple_int_printing.c` |
| **Type** | C source |
| **Module** | `02-variables-and-types` |
| **Lines** | 6 total (4 code, 0 comments) |
| **Libraries** | `stdio.h` |
| **Topics** | Fundamentals |

## What It Does

Basic integer output with `printf()`. Covers format specifiers `%d`, `%i`, `%u`, `%x`, `%o`, width/precision modifiers, and common formatting patterns.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (1 calls) to display output to the console
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
gcc simple_int_printing.c -o simple_int_printing -std=c11 -Wall -Wextra -g

# Run
./simple_int_printing

# Compile with Clang
clang simple_int_printing.c -o simple_int_printing -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc simple_int_printing.c -o simple_int_printing -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
