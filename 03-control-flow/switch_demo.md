# `switch_demo.c`

> switch_demo.c
Demonstrates proper use of switch statements
Topics: switch-case, break, default, fall-through

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `03-control-flow/switch_demo.c` |
| **Type** | C source |
| **Module** | `03-control-flow` |
| **Lines** | 115 total (96 code, 10 comments) |
| **Libraries** | `stdio.h` |
| **Topics** | Switch Case, Enum |

## What It Does

Illustrates the `switch` statement for multi-way branching. Covers fall-through behavior, `default` cases, and when to prefer `switch` over chained `if-else`.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (30 calls) to display output to the console
5. Makes decisions using conditional statements (2 branches)
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
gcc switch_demo.c -o switch_demo -std=c11 -Wall -Wextra -g

# Run
./switch_demo

# Compile with Clang
clang switch_demo.c -o switch_demo -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc switch_demo.c -o switch_demo -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
