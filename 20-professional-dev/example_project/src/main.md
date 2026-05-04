# `main.c`

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `20-professional-dev/example_project/src/main.c` |
| **Type** | C source |
| **Module** | `src` |
| **Lines** | 16 total (9 code, 0 comments) |
| **Libraries** | `stdio.h`, `math_utils.h` |
| **Topics** | Fundamentals |

## What It Does

Entry point for the professional development example project. Demonstrates proper project structure with header files, separate compilation, and organized directory layout (`src/`, `include/`, `lib/`, `tests/`).

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (5 calls) to display output to the console
7. Returns 0 to indicate successful completion

## Key Code Patterns

```c
#include <stdio.h>
#include <math_utils.h>

int main(void) {
    // ... program logic ...
    return 0;
}
```

## Libraries Used

- **`<stdio.h>`** — Standard I/O: `printf()`, `scanf()`, `fgets()`, `FILE` operations
- **`<math_utils.h>`** — Standard C library

## Compilation

```bash
cd 20-professional-dev/example_project/src

# Compile with GCC (debug build)
gcc main.c -o main -std=c11 -Wall -Wextra -g

# Run
./main

# Compile with Clang
clang main.c -o main -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc main.c -o main -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`
- **Library header:** `<math_utils.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
