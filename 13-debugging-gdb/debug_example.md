# `debug_example.c`

> debug_example.c
Example program for GDB debugging practice
This program has a bug - can you find it with GDB?

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `13-debugging-gdb/debug_example.c` |
| **Type** | C source |
| **Module** | `13-debugging-gdb` |
| **Lines** | 51 total (32 code, 8 comments) |
| **Libraries** | `stdio.h` |
| **Topics** | Debugging |

## What It Does

Files designed for GDB debugging practice. Contains deliberate crash scenarios (segfaults, buffer overflows, use-after-free) and logic errors to trace with breakpoints, watchpoints, and memory inspection.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (8 calls) to display output to the console
5. Makes decisions using conditional statements (1 branches)
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
| `factorial()` | `int` | `int n` | See implementation for details |
| `sum_array()` | `int` | `int *arr, int size` | See implementation for details |

## Compilation

```bash
cd 13-debugging-gdb

# Compile with GCC (debug build)
gcc debug_example.c -o debug_example -std=c11 -Wall -Wextra -g

# Run
./debug_example

# Compile with Clang
clang debug_example.c -o debug_example -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc debug_example.c -o debug_example -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
