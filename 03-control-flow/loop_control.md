# `loop_control.c`

> loop_control.c
Demonstrates break and continue statements
Topics: break, continue, loop control flow

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `03-control-flow/loop_control.c` |
| **Type** | C source |
| **Module** | `03-control-flow` |
| **Lines** | 163 total (119 code, 17 comments) |
| **Libraries** | `stdio.h` |
| **Topics** | Fundamentals |

## What It Does

This program demonstrates key concepts from the **03-control-flow** module. Compile and run it to see the concepts in action. Study the source code and experiment by making modifications.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (43 calls) to display output to the console
5. Makes decisions using conditional statements (11 branches)
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
gcc loop_control.c -o loop_control -std=c11 -Wall -Wextra -g

# Run
./loop_control

# Compile with Clang
clang loop_control.c -o loop_control -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc loop_control.c -o loop_control -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
