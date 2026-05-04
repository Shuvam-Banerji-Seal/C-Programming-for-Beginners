# `conditionals.c`

> conditionals.c
Demonstrates various conditional statements in C
Topics: if, else, else-if, nested conditionals

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `03-control-flow/conditionals.c` |
| **Type** | C source |
| **Module** | `03-control-flow` |
| **Lines** | 77 total (54 code, 12 comments) |
| **Libraries** | `stdio.h` |
| **Topics** | If Else |

## What It Does

Demonstrates C's conditional execution: `if`, `else if`, `else`, and the ternary `?:` operator. Shows real-world patterns for decision-making in programs, including nested conditions and boolean logic.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (22 calls) to display output to the console
5. Makes decisions using conditional statements (6 branches)
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
gcc conditionals.c -o conditionals -std=c11 -Wall -Wextra -g

# Run
./conditionals

# Compile with Clang
clang conditionals.c -o conditionals -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc conditionals.c -o conditionals -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`
- **Buggy version:** [`conditionals_buggy.c`](conditionals_buggy.c) (learn from common mistakes)

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
