# `watchpoint_example.c`

> watchpoint_example.c
Example for practicing GDB watchpoints
Learn to track when variables change

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `13-debugging-gdb/watchpoint_example.c` |
| **Type** | C source |
| **Module** | `13-debugging-gdb` |
| **Lines** | 53 total (31 code, 7 comments) |
| **Libraries** | `stdio.h` |
| **Topics** | Functions |

## What It Does

Files designed for GDB debugging practice. Contains deliberate crash scenarios (segfaults, buffer overflows, use-after-free) and logic errors to trace with breakpoints, watchpoints, and memory inspection.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (16 calls) to display output to the console
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
| `increment_counter()` | `void` | `int amount` | See implementation for details |
| `reset_counter()` | `void` | `` | See implementation for details |

## Compilation

```bash
cd 13-debugging-gdb

# Compile with GCC (debug build)
gcc watchpoint_example.c -o watchpoint_example -std=c11 -Wall -Wextra -g

# Run
./watchpoint_example

# Compile with Clang
clang watchpoint_example.c -o watchpoint_example -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc watchpoint_example.c -o watchpoint_example -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
