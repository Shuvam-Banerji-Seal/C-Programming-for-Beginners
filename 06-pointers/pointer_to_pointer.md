# `pointer_to_pointer.c`

> pointer_to_pointer.c
Demonstrates pointer to pointer (double pointers)
Topics: Double pointers, triple pointers, use cases

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `06-pointers/pointer_to_pointer.c` |
| **Type** | C source |
| **Module** | `06-pointers` |
| **Lines** | 151 total (99 code, 23 comments) |
| **Libraries** | `stdio.h`, `stdlib.h`, `string.h` |
| **Topics** | Double Pointer |

## What It Does

This program demonstrates key concepts from the **06-pointers** module. Compile and run it to see the concepts in action. Study the source code and experiment by making modifications.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (48 calls) to display output to the console
4. Allocates memory dynamically on the heap
5. Makes decisions using conditional statements (2 branches)
7. Returns 0 to indicate successful completion

## Key Code Patterns

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // ... program logic ...
    return 0;
}
```

## Libraries Used

- **`<stdio.h>`** — Standard I/O: `printf()`, `scanf()`, `fgets()`, `FILE` operations
- **`<stdlib.h>`** — Standard library: `malloc()`, `free()`, `atoi()`, `rand()`, `exit()`
- **`<string.h>`** — String manipulation: `strlen()`, `strcpy()`, `strcmp()`, `strcat()`

## Functions

| Function | Returns | Parameters | Purpose |
|----------|---------|------------|---------|
| `allocate_memory()` | `void` | `int **ptr, int value` | See implementation for details |
| `swap_pointers()` | `void` | `int **p1, int **p2` | See implementation for details |

## Compilation

```bash
cd 06-pointers

# Compile with GCC (debug build)
gcc pointer_to_pointer.c -o pointer_to_pointer -std=c11 -Wall -Wextra -g

# Run
./pointer_to_pointer

# Compile with Clang
clang pointer_to_pointer.c -o pointer_to_pointer -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc pointer_to_pointer.c -o pointer_to_pointer -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`
- **Library header:** `<stdlib.h>`
- **Library header:** `<string.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
