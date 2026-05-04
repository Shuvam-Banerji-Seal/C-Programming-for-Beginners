# `lets_do_2d_arrays.c`

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `fundamentals/lets_do_2d_arrays.c` |
| **Type** | C source |
| **Module** | `fundamentals` |
| **Lines** | 21 total (14 code, 0 comments) |
| **Libraries** | `stdio.h` |
| **Topics** | Fundamentals |

## What It Does

Hands-on practice with a specific C concept. Compile and run to see the demonstrated behavior, then modify the code to experiment.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (2 calls) to display output to the console
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
gcc lets_do_2d_arrays.c -o lets_do_2d_arrays -std=c11 -Wall -Wextra -g

# Run
./lets_do_2d_arrays

# Compile with Clang
clang lets_do_2d_arrays.c -o lets_do_2d_arrays -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc lets_do_2d_arrays.c -o lets_do_2d_arrays -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
