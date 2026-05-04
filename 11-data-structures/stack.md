# `stack.c`

> stack.c
Implements a stack data structure
Topics: LIFO, push, pop, peek

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `11-data-structures/stack.c` |
| **Type** | C source |
| **Module** | `11-data-structures` |
| **Lines** | 64 total (43 code, 5 comments) |
| **Libraries** | `stdio.h`, `stdlib.h` |
| **Topics** | Typedef |

## What It Does

This program demonstrates key concepts from the **11-data-structures** module. Compile and run it to see the concepts in action. Study the source code and experiment by making modifications.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (9 calls) to display output to the console
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
| `init_stack()` | `void` | `Stack *s` | See implementation for details |
| `is_empty()` | `int` | `Stack *s` | See implementation for details |
| `is_full()` | `int` | `Stack *s` | See implementation for details |
| `push()` | `void` | `Stack *s, int value` | See implementation for details |
| `pop()` | `int` | `Stack *s` | See implementation for details |

## Constants & Macros

| Name | Value |
|------|-------|
| `MAX_SIZE` | Defined in source |

## Compilation

```bash
cd 11-data-structures

# Compile with GCC (debug build)
gcc stack.c -o stack -std=c11 -Wall -Wextra -g

# Run
./stack

# Compile with Clang
clang stack.c -o stack -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc stack.c -o stack -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`
- **Library header:** `<stdlib.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
