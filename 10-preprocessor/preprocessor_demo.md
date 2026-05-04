# `preprocessor_demo.c`

> preprocessor_demo.c
Demonstrates C preprocessor directives
Topics: #define, #include, #ifdef, macros, conditional compilation

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `10-preprocessor/preprocessor_demo.c` |
| **Type** | C source |
| **Module** | `10-preprocessor` |
| **Lines** | 56 total (32 code, 12 comments) |
| **Libraries** | `stdio.h` |
| **Topics** | Preprocessor |

## What It Does

Explores the C preprocessor: `#define` macros (with and without parameters), `#include`, `#ifdef`/`#ifndef` for conditional compilation, `#pragma`, and the `##` token pasting operator.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (18 calls) to display output to the console
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

## Constants & Macros

| Name | Value |
|------|-------|
| `PI` | Defined in source |
| `MAX_SIZE` | Defined in source |
| `SQUARE` | Defined in source |
| `MAX` | Defined in source |
| `PRINT_VAR` | Defined in source |
| `DEBUG_MODE` | Defined in source |

## Compilation

```bash
cd 10-preprocessor

# Compile with GCC (debug build)
gcc preprocessor_demo.c -o preprocessor_demo -std=c11 -Wall -Wextra -g

# Run
./preprocessor_demo

# Compile with Clang
clang preprocessor_demo.c -o preprocessor_demo -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc preprocessor_demo.c -o preprocessor_demo -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
