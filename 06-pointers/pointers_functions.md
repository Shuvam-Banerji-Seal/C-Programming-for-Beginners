# `pointers_functions.c`

> pointers_functions.c
Demonstrates pointers with functions
Topics: Pass by value vs reference, returning pointers, function pointers

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `06-pointers/pointers_functions.c` |
| **Type** | C source |
| **Module** | `06-pointers` |
| **Lines** | 168 total (105 code, 29 comments) |
| **Libraries** | `stdio.h`, `stdlib.h` |
| **Topics** | Function Pointer |

## What It Does

This program demonstrates key concepts from the **06-pointers** module. Compile and run it to see the concepts in action. Study the source code and experiment by making modifications.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (35 calls) to display output to the console
4. Allocates memory dynamically on the heap
5. Makes decisions using conditional statements (2 branches)
7. Returns 0 to indicate successful completion

## Key Code Patterns

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // ... program logic ...
    return 0;
}
```

## Libraries Used

- **`<stdio.h>`** — Standard I/O: `printf()`, `scanf()`, `fgets()`, `FILE` operations
- **`<stdlib.h>`** — Standard library: `malloc()`, `free()`, `atoi()`, `rand()`, `exit()`

## Functions

| Function | Returns | Parameters | Purpose |
|----------|---------|------------|---------|
| `increment_value()` | `void` | `int x` | See implementation for details |
| `increment_reference()` | `void` | `int *x` | See implementation for details |
| `swap()` | `void` | `int *a, int *b` | See implementation for details |
| `add()` | `int` | `int a, int b` | See implementation for details |
| `subtract()` | `int` | `int a, int b` | See implementation for details |
| `multiply()` | `int` | `int a, int b` | See implementation for details |
| `print_array()` | `void` | `int *arr, int size` | See implementation for details |
| `double_array_values()` | `void` | `int *arr, int size` | See implementation for details |

## Compilation

```bash
cd 06-pointers

# Compile with GCC (debug build)
gcc pointers_functions.c -o pointers_functions -std=c11 -Wall -Wextra -g

# Run
./pointers_functions

# Compile with Clang
clang pointers_functions.c -o pointers_functions -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc pointers_functions.c -o pointers_functions -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`
- **Library header:** `<stdlib.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
