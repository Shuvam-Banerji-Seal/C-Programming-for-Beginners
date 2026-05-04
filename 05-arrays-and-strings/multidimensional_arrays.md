# `multidimensional_arrays.c`

> multidimensional_arrays.c
Advanced multi-dimensional array operations
Topics: 2D arrays, 3D arrays, matrix operations, dynamic allocation

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `05-arrays-and-strings/multidimensional_arrays.c` |
| **Type** | C source |
| **Module** | `05-arrays-and-strings` |
| **Lines** | 220 total (162 code, 24 comments) |
| **Libraries** | `stdio.h`, `stdlib.h` |
| **Topics** | Multi Dimensional Arrays |

## What It Does

Working with 2D and 3D arrays in C: declaration, initialization, row-major vs column-major traversal, passing to functions, and dynamic allocation of multi-dimensional arrays.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (38 calls) to display output to the console
5. Makes decisions using conditional statements (4 branches)
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
| `matrixAdd()` | `void` | `int rows, int cols, int a[rows][cols], int b[rows]...` | See implementation for details |
| `matrixMultiply()` | `void` | `int r1, int c1, int a[r1][c1], int r2, int c2, int...` | See implementation for details |
| `matrixTranspose()` | `void` | `int rows, int cols, int matrix[rows][cols], int re...` | See implementation for details |
| `printMatrix()` | `void` | `int rows, int cols, int matrix[rows][cols]` | See implementation for details |
| `spiralTraversal()` | `void` | `int rows, int cols, int matrix[rows][cols]` | See implementation for details |
| `searchMatrix()` | `int` | `int rows, int cols, int matrix[rows][cols], int ta...` | See implementation for details |
| `demonstrate3DArray()` | `void` | `` | See implementation for details |

## Compilation

```bash
cd 05-arrays-and-strings

# Compile with GCC (debug build)
gcc multidimensional_arrays.c -o multidimensional_arrays -std=c11 -Wall -Wextra -g

# Run
./multidimensional_arrays

# Compile with Clang
clang multidimensional_arrays.c -o multidimensional_arrays -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc multidimensional_arrays.c -o multidimensional_arrays -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`
- **Library header:** `<stdlib.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
