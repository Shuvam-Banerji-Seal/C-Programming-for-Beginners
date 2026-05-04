# `segfault_example.c`

> segfault_example.c
Example program that demonstrates common segmentation faults
Use GDB to find and understand the crashes

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `13-debugging-gdb/segfault_example.c` |
| **Type** | C source |
| **Module** | `13-debugging-gdb` |
| **Lines** | 67 total (44 code, 11 comments) |
| **Libraries** | `stdio.h`, `stdlib.h` |
| **Topics** | Debugging |

## What It Does

Files designed for GDB debugging practice. Contains deliberate crash scenarios (segfaults, buffer overflows, use-after-free) and logic errors to trace with breakpoints, watchpoints, and memory inspection.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (22 calls) to display output to the console
4. Allocates memory dynamically on the heap
5. Makes decisions using conditional statements (1 branches)
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
| `example1_null_pointer()` | `void` | `` | See implementation for details |
| `example2_buffer_overflow()` | `void` | `` | See implementation for details |
| `example3_use_after_free()` | `void` | `` | See implementation for details |
| `example4_stack_overflow()` | `void` | `` | See implementation for details |

## Compilation

```bash
cd 13-debugging-gdb

# Compile with GCC (debug build)
gcc segfault_example.c -o segfault_example -std=c11 -Wall -Wextra -g

# Run
./segfault_example

# Compile with Clang
clang segfault_example.c -o segfault_example -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc segfault_example.c -o segfault_example -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`
- **Library header:** `<stdlib.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
