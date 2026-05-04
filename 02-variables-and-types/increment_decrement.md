# `increment_decrement.c`

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `02-variables-and-types/increment_decrement.c` |
| **Type** | C source |
| **Module** | `02-variables-and-types` |
| **Lines** | 41 total (28 code, 0 comments) |
| **Libraries** | `stdio.h` |
| **Topics** | Fundamentals |

## What It Does

Pre-increment (`++x`) vs post-increment (`x++`) and their effect on expressions. A common source of bugs — this file clarifies the behavior with annotated examples.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (22 calls) to display output to the console
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
cd 02-variables-and-types

# Compile with GCC (debug build)
gcc increment_decrement.c -o increment_decrement -std=c11 -Wall -Wextra -g

# Run
./increment_decrement

# Compile with Clang
clang increment_decrement.c -o increment_decrement -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc increment_decrement.c -o increment_decrement -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
