# `stack_vs_heap.c`

> stack_vs_heap.c
Demonstrates the difference between stack and heap memory
Topics: Stack allocation, heap allocation, scope, lifetime

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `07-memory-management/stack_vs_heap.c` |
| **Type** | C source |
| **Module** | `07-memory-management` |
| **Lines** | 150 total (99 code, 23 comments) |
| **Libraries** | `stdio.h`, `stdlib.h` |
| **Topics** | Stack Vs Heap, Heap |

## What It Does

Compares stack vs heap memory: allocation speed, lifetime, size limits, and when to use each. Shows how local variables live on the stack while dynamically allocated memory lives on the heap.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (58 calls) to display output to the console
4. Allocates memory dynamically on the heap
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
| `stack_example()` | `void` | `` | See implementation for details |

## Compilation

```bash
cd 07-memory-management

# Compile with GCC (debug build)
gcc stack_vs_heap.c -o stack_vs_heap -std=c11 -Wall -Wextra -g

# Run
./stack_vs_heap

# Compile with Clang
clang stack_vs_heap.c -o stack_vs_heap -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc stack_vs_heap.c -o stack_vs_heap -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`
- **Library header:** `<stdlib.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
