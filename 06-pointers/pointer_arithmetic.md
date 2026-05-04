# `pointer_arithmetic.c`

> pointer_arithmetic.c
Demonstrates pointer arithmetic in C
Topics: Pointer increment/decrement, pointer addition/subtraction,
pointer difference, relationship with arrays

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `06-pointers/pointer_arithmetic.c` |
| **Type** | C source |
| **Module** | `06-pointers` |
| **Lines** | 163 total (118 code, 15 comments) |
| **Libraries** | `stdio.h` |
| **Topics** | Pointer Arithmetic |

## What It Does

Demonstrates pointer arithmetic: incrementing/decrementing pointers, adding offsets, and how array indexing relates to pointer math. Explains why `ptr + 1` advances by the size of the pointed-to type.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (61 calls) to display output to the console
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

## Compilation

```bash
cd 06-pointers

# Compile with GCC (debug build)
gcc pointer_arithmetic.c -o pointer_arithmetic -std=c11 -Wall -Wextra -g

# Run
./pointer_arithmetic

# Compile with Clang
clang pointer_arithmetic.c -o pointer_arithmetic -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc pointer_arithmetic.c -o pointer_arithmetic -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
