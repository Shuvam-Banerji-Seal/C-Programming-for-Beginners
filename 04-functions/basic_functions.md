# `basic_functions.c`

> Function declarations

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `04-functions/basic_functions.c` |
| **Type** | C source |
| **Module** | `04-functions` |
| **Lines** | 63 total (44 code, 4 comments) |
| **Libraries** | `stdio.h` |
| **Topics** | Functions |

## What It Does

This program demonstrates key concepts from the **04-functions** module. Compile and run it to see the concepts in action. Study the source code and experiment by making modifications.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (9 calls) to display output to the console
5. Makes decisions using conditional statements (3 branches)
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

## Functions

| Function | Returns | Parameters | Purpose |
|----------|---------|------------|---------|
| `greet()` | `void` | `void` | See implementation for details |
| `add()` | `int` | `int a, int b` | See implementation for details |
| `subtract()` | `int` | `int a, int b` | See implementation for details |
| `divide()` | `float` | `float a, float b` | See implementation for details |
| `maximum()` | `int` | `int a, int b, int c` | See implementation for details |
| `printLine()` | `void` | `int length` | See implementation for details |

## Compilation

```bash
cd 04-functions

# Compile with GCC (debug build)
gcc basic_functions.c -o basic_functions -std=c11 -Wall -Wextra -g

# Run
./basic_functions

# Compile with Clang
clang basic_functions.c -o basic_functions -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc basic_functions.c -o basic_functions -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
