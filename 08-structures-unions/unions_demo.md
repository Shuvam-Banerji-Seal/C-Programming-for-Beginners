# `unions_demo.c`

> unions_demo.c
Demonstrates unions in C
Topics: union definition, memory sharing, use cases

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `08-structures-unions/unions_demo.c` |
| **Type** | C source |
| **Module** | `08-structures-unions` |
| **Lines** | 51 total (28 code, 10 comments) |
| **Libraries** | `stdio.h`, `string.h` |
| **Topics** | Unions, Typedef |

## What It Does

Bit fields allow packing multiple variables into a single integer type, saving memory. Unions let different data types share the same memory location. Essential for embedded systems, protocol parsing, and low-level programming.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (11 calls) to display output to the console
7. Returns 0 to indicate successful completion

## Key Code Patterns

```c
#include <stdio.h>
#include <string.h>

int main(void) {
    // ... program logic ...
    return 0;
}
```

## Libraries Used

- **`<stdio.h>`** — Standard I/O: `printf()`, `scanf()`, `fgets()`, `FILE` operations
- **`<string.h>`** — String manipulation: `strlen()`, `strcpy()`, `strcmp()`, `strcat()`

## Compilation

```bash
cd 08-structures-unions

# Compile with GCC (debug build)
gcc unions_demo.c -o unions_demo -std=c11 -Wall -Wextra -g

# Run
./unions_demo

# Compile with Clang
clang unions_demo.c -o unions_demo -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc unions_demo.c -o unions_demo -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`
- **Library header:** `<string.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
