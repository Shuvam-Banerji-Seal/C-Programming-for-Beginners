# `using_strings_in_c.c`

> * --> Value at address
& --> Address of variable
*(arr+i) == arr[i]

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `fundamentals/using_strings_in_c.c` |
| **Type** | C source |
| **Module** | `fundamentals` |
| **Lines** | 42 total (19 code, 12 comments) |
| **Libraries** | `stdio.h` |
| **Topics** | Strings |

## What It Does

String manipulation in C without `string.h`. Implements `strlen`, `strcpy`, `strcmp`, `strcat`, and other operations from scratch — building deep understanding of how strings work as null-terminated character arrays.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (8 calls) to display output to the console
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
| `array_general()` | `void` | `` | See implementation for details |

## Compilation

```bash
cd fundamentals

# Compile with GCC (debug build)
gcc using_strings_in_c.c -o using_strings_in_c -std=c11 -Wall -Wextra -g

# Run
./using_strings_in_c

# Compile with Clang
clang using_strings_in_c.c -o using_strings_in_c -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc using_strings_in_c.c -o using_strings_in_c -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
