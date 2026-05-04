# `loops_buggy.c`

> loops_buggy.c
DELIBERATELY BUGGY CODE - For learning purposes
This file contains common mistakes with loops.
Each bug is explained with comments.

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `03-control-flow/loops_buggy.c` |
| **Type** | C source |
| **Module** | `03-control-flow` |
| **Lines** | 119 total (72 code, 31 comments) |
| **Libraries** | `stdio.h` |
| **Topics** | Loops, Buggy Example |

## What It Does

This file contains **deliberately introduced bugs** for educational purposes. Study the code, identify the errors, compile to see what warnings/errors GCC and Clang produce, then fix them. This is an essential learning technique — understanding what *not* to do.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (44 calls) to display output to the console
5. Makes decisions using conditional statements (3 branches)
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

## Known Bugs

This file contains deliberate errors. Common categories:
- **Memory bugs**: leaks, double-free, use-after-free
- **Pointer bugs**: null dereference, dangling pointers
- **Logic bugs**: off-by-one, incorrect conditions
- **IO bugs**: unformatted input, buffer overflow

Compile with full warnings and address sanitizer to detect them:
```bash
gcc loops_buggy.c -o loops_buggy -std=c11 -Wall -Wextra -Werror -fsanitize=address
```

## Compilation

```bash
cd 03-control-flow

# Compile with GCC (debug build)
gcc loops_buggy.c -o loops_buggy -std=c11 -Wall -Wextra -g

# Run
./loops_buggy

# Compile with Clang
clang loops_buggy.c -o loops_buggy -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc loops_buggy.c -o loops_buggy -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
