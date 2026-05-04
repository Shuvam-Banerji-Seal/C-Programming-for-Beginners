# `loops_performance_comparision.c`

> --- For loop ---

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `fundamentals/loops_performance_comparision.c` |
| **Type** | C source |
| **Module** | `fundamentals` |
| **Lines** | 49 total (37 code, 3 comments) |
| **Libraries** | `stdio.h`, `time.h` |
| **Topics** | Loops |

## What It Does

Covers all three loop constructs in C: `for`, `while`, and `do-while`. Demonstrates when to use each type, how to control loop flow with `break` and `continue`, and common iteration patterns.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (3 calls) to display output to the console
5. Makes decisions using conditional statements (1 branches)
7. Returns 0 to indicate successful completion

## Key Code Patterns

```c
#include <stdio.h>
#include <time.h>

int main(void) {
    // ... program logic ...
    return 0;
}
```

## Libraries Used

- **`<stdio.h>`** — Standard I/O: `printf()`, `scanf()`, `fgets()`, `FILE` operations
- **`<time.h>`** — Time: `time()`, `clock()`, `srand()`, `rand()`

## Constants & Macros

| Name | Value |
|------|-------|
| `N` | Defined in source |

## Compilation

```bash
cd fundamentals

# Compile with GCC (debug build)
gcc loops_performance_comparision.c -o loops_performance_comparision -std=c11 -Wall -Wextra -g

# Run
./loops_performance_comparision

# Compile with Clang
clang loops_performance_comparision.c -o loops_performance_comparision -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc loops_performance_comparision.c -o loops_performance_comparision -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`
- **Library header:** `<time.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
