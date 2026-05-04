# `loops_in_c.c`

> For Loop

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `fundamentals/loops_in_c.c` |
| **Type** | C source |
| **Module** | `fundamentals` |
| **Lines** | 31 total (23 code, 3 comments) |
| **Libraries** | `stdio.h` |
| **Topics** | Loops |

## What It Does

Covers all three loop constructs in C: `for`, `while`, and `do-while`. Demonstrates when to use each type, how to control loop flow with `break` and `continue`, and common iteration patterns.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (10 calls) to display output to the console
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
cd fundamentals

# Compile with GCC (debug build)
gcc loops_in_c.c -o loops_in_c -std=c11 -Wall -Wextra -g

# Run
./loops_in_c

# Compile with Clang
clang loops_in_c.c -o loops_in_c -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc loops_in_c.c -o loops_in_c -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
