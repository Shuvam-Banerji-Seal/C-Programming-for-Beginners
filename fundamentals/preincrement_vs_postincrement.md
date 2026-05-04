# `preincrement_vs_postincrement.c`

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `fundamentals/preincrement_vs_postincrement.c` |
| **Type** | C source |
| **Module** | `fundamentals` |
| **Lines** | 41 total (28 code, 0 comments) |
| **Libraries** | `stdio.h` |
| **Topics** | Fundamentals |

## What It Does

Deep dive into pre vs post increment: generated assembly comparison (GCC vs Clang), performance implications, and common bugs. Shows the actual machine code each produces.

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
gcc preincrement_vs_postincrement.c -o preincrement_vs_postincrement -std=c11 -Wall -Wextra -g

# Run
./preincrement_vs_postincrement

# Compile with Clang
clang preincrement_vs_postincrement.c -o preincrement_vs_postincrement -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc preincrement_vs_postincrement.c -o preincrement_vs_postincrement -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
