# `pointers_arrays.c`

> pointers_arrays.c
Demonstrates the relationship between pointers and arrays
Topics: Array decay, pointer equivalence, multi-dimensional arrays

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `06-pointers/pointers_arrays.c` |
| **Type** | C source |
| **Module** | `06-pointers` |
| **Lines** | 137 total (96 code, 16 comments) |
| **Libraries** | `stdio.h` |
| **Topics** | Pointer Array Relationship |

## What It Does

Clarifies the relationship between arrays and pointers in C. Shows how an array name decays to a pointer, how to iterate using pointers vs indices, and the equivalence of `arr[i]` and `*(arr + i)`.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (52 calls) to display output to the console
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
cd 06-pointers

# Compile with GCC (debug build)
gcc pointers_arrays.c -o pointers_arrays -std=c11 -Wall -Wextra -g

# Run
./pointers_arrays

# Compile with Clang
clang pointers_arrays.c -o pointers_arrays -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc pointers_arrays.c -o pointers_arrays -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
