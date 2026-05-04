# `functions_in_c.c`

> functions declaration

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `fundamentals/functions_in_c.c` |
| **Type** | C source |
| **Module** | `fundamentals` |
| **Lines** | 58 total (38 code, 8 comments) |
| **Libraries** | `stdio.h` |
| **Topics** | Functions |

## What It Does

Function fundamentals: declaration vs definition, parameters, return values, prototypes, and the importance of declaring functions before use. Building block of modular C programming.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (6 calls) to display output to the console
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
| `function1()` | `void` | `` | See implementation for details |
| `function2()` | `void` | `int a` | See implementation for details |
| `function3()` | `char` | `` | See implementation for details |
| `function4()` | `int` | `int a, int b` | See implementation for details |
| `function5()` | `float` | `float a, float b` | See implementation for details |
| `function6()` | `int` | `float a, float b` | See implementation for details |

## Compilation

```bash
cd fundamentals

# Compile with GCC (debug build)
gcc functions_in_c.c -o functions_in_c -std=c11 -Wall -Wextra -g

# Run
./functions_in_c

# Compile with Clang
clang functions_in_c.c -o functions_in_c -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc functions_in_c.c -o functions_in_c -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
