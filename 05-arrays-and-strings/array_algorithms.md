# `array_algorithms.c`

> Linear search

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `05-arrays-and-strings/array_algorithms.c` |
| **Type** | C source |
| **Module** | `05-arrays-and-strings` |
| **Lines** | 127 total (95 code, 12 comments) |
| **Libraries** | `stdio.h` |
| **Topics** | Functions |

## What It Does

Common array algorithms implemented in C: linear/binary search, sorting (bubble, selection, insertion), reversing, rotation, and merging. Builds foundation for algorithm analysis.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (11 calls) to display output to the console
5. Makes decisions using conditional statements (5 branches)
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
| `linearSearch()` | `int` | `int arr[], int size, int target` | See implementation for details |
| `binarySearch()` | `int` | `int arr[], int size, int target` | See implementation for details |
| `bubbleSort()` | `void` | `int arr[], int size` | See implementation for details |
| `selectionSort()` | `void` | `int arr[], int size` | See implementation for details |
| `printArray()` | `void` | `int arr[], int size` | See implementation for details |
| `findMax()` | `int` | `int arr[], int size` | See implementation for details |
| `reverseArray()` | `void` | `int arr[], int size` | See implementation for details |

## Compilation

```bash
cd 05-arrays-and-strings

# Compile with GCC (debug build)
gcc array_algorithms.c -o array_algorithms -std=c11 -Wall -Wextra -g

# Run
./array_algorithms

# Compile with Clang
clang array_algorithms.c -o array_algorithms -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc array_algorithms.c -o array_algorithms -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
