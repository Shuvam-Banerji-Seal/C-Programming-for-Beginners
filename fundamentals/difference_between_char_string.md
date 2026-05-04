# `difference_between_char_string.c`

> Print the character and its size

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `fundamentals/difference_between_char_string.c` |
| **Type** | C source |
| **Module** | `fundamentals` |
| **Lines** | 28 total (17 code, 3 comments) |
| **Libraries** | `stdio.h` |
| **Topics** | Strings |

## What It Does

String manipulation in C without `string.h`. Implements `strlen`, `strcpy`, `strcmp`, `strcat`, and other operations from scratch — building deep understanding of how strings work as null-terminated character arrays.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (7 calls) to display output to the console
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
gcc difference_between_char_string.c -o difference_between_char_string -std=c11 -Wall -Wextra -g

# Run
./difference_between_char_string

# Compile with Clang
clang difference_between_char_string.c -o difference_between_char_string -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc difference_between_char_string.c -o difference_between_char_string -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
