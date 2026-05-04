# `pass_by_value_reference.c`

> Pass by value

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `04-functions/pass_by_value_reference.c` |
| **Type** | C source |
| **Module** | `04-functions` |
| **Lines** | 72 total (45 code, 13 comments) |
| **Libraries** | `stdio.h` |
| **Topics** | Functions |

## What It Does

C is always pass-by-value, but pointers enable pass-by-reference semantics. This file clarifies the distinction with clear examples showing when and why to use pointers as function parameters.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (16 calls) to display output to the console
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

## Functions

| Function | Returns | Parameters | Purpose |
|----------|---------|------------|---------|
| `tryToModify()` | `void` | `int x` | See implementation for details |
| `modify()` | `void` | `int *x` | See implementation for details |
| `swap()` | `void` | `int *a, int *b` | See implementation for details |
| `getMinMax()` | `void` | `int arr[], int size, int *min, int *max` | See implementation for details |

## Compilation

```bash
cd 04-functions

# Compile with GCC (debug build)
gcc pass_by_value_reference.c -o pass_by_value_reference -std=c11 -Wall -Wextra -g

# Run
./pass_by_value_reference

# Compile with Clang
clang pass_by_value_reference.c -o pass_by_value_reference -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc pass_by_value_reference.c -o pass_by_value_reference -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
