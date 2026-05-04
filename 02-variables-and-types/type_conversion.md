# `type_conversion.c`

> type_conversion.c
Demonstrates implicit and explicit type conversion

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `02-variables-and-types/type_conversion.c` |
| **Type** | C source |
| **Module** | `02-variables-and-types` |
| **Lines** | 60 total (37 code, 10 comments) |
| **Libraries** | `stdio.h` |
| **Topics** | Fundamentals |

## What It Does

Type conversion in C: implicit vs explicit casting, integer promotion, arithmetic conversion rules, and potential pitfalls like truncation, sign extension, and overflow.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (17 calls) to display output to the console
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
gcc type_conversion.c -o type_conversion -std=c11 -Wall -Wextra -g

# Run
./type_conversion

# Compile with Clang
clang type_conversion.c -o type_conversion -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc type_conversion.c -o type_conversion -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
