# `function_pointers.c`

> Arithmetic operations

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `04-functions/function_pointers.c` |
| **Type** | C source |
| **Module** | `04-functions` |
| **Lines** | 94 total (61 code, 9 comments) |
| **Libraries** | `stdio.h` |
| **Topics** | Typedef |

## What It Does

Function pointers enable callbacks, dispatch tables, and runtime polymorphism in C. This file shows how to declare, assign, and invoke function pointers, with practical examples like sorting with custom comparators.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (25 calls) to display output to the console
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
| `add()` | `int` | `int a, int b` | See implementation for details |
| `subtract()` | `int` | `int a, int b` | See implementation for details |
| `multiply()` | `int` | `int a, int b` | See implementation for details |
| `divide()` | `int` | `int a, int b` | See implementation for details |
| `forEach()` | `void` | `int arr[], int size, PrintCallback callback` | See implementation for details |
| `printDouble()` | `void` | `int n` | See implementation for details |
| `printSquare()` | `void` | `int n` | See implementation for details |
| `printCube()` | `void` | `int n` | See implementation for details |

## Compilation

```bash
cd 04-functions

# Compile with GCC (debug build)
gcc function_pointers.c -o function_pointers -std=c11 -Wall -Wextra -g

# Run
./function_pointers

# Compile with Clang
clang function_pointers.c -o function_pointers -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc function_pointers.c -o function_pointers -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
