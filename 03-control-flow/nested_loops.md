# `nested_loops.c`

> nested_loops.c
Demonstrates nested loops and pattern printing
Topics: Nested loops, pattern printing, multiplication tables

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `03-control-flow/nested_loops.c` |
| **Type** | C source |
| **Module** | `03-control-flow` |
| **Lines** | 144 total (107 code, 21 comments) |
| **Libraries** | `stdio.h` |
| **Topics** | Loops, Nested Loops |

## What It Does

Covers all three loop constructs in C: `for`, `while`, and `do-while`. Demonstrates when to use each type, how to control loop flow with `break` and `continue`, and common iteration patterns.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (42 calls) to display output to the console
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

## Compilation

```bash
cd 03-control-flow

# Compile with GCC (debug build)
gcc nested_loops.c -o nested_loops -std=c11 -Wall -Wextra -g

# Run
./nested_loops

# Compile with Clang
clang nested_loops.c -o nested_loops -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc nested_loops.c -o nested_loops -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
