# `basic_io.c`

> basic_io.c
Demonstrates basic input/output operations in C

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `01-basics/basic_io.c` |
| **Type** | C source |
| **Module** | `01-basics` |
| **Lines** | 38 total (20 code, 8 comments) |
| **Libraries** | `stdio.h` |
| **Topics** | Input Output |

## What It Does

A comprehensive demonstration of C input/output functions. Covers `printf()` format specifiers, `scanf()` for various data types, `getchar()`/`putchar()` for character I/O, and best practices for safe input handling.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (11 calls) to display output to the console
3. Uses `scanf()` (3 calls) to read user input
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
cd 01-basics

# Compile with GCC (debug build)
gcc basic_io.c -o basic_io -std=c11 -Wall -Wextra -g

# Run
./basic_io

# Compile with Clang
clang basic_io.c -o basic_io -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc basic_io.c -o basic_io -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
