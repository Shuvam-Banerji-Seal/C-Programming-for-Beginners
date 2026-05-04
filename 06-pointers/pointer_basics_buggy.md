# `pointer_basics_buggy.c`

> pointer_basics_buggy.c
DELIBERATELY BUGGY CODE - For learning purposes
This file contains common pointer mistakes.
Each bug is explained with comments.

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `06-pointers/pointer_basics_buggy.c` |
| **Type** | C source |
| **Module** | `06-pointers` |
| **Lines** | 142 total (77 code, 45 comments) |
| **Libraries** | `stdio.h`, `stdlib.h` |
| **Topics** | Buggy Example, Pointer Basics |

## What It Does

This file contains **deliberately introduced bugs** for educational purposes. Study the code, identify the errors, compile to see what warnings/errors GCC and Clang produce, then fix them. This is an essential learning technique — understanding what *not* to do.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (44 calls) to display output to the console
4. Allocates memory dynamically on the heap
5. Makes decisions using conditional statements (3 branches)
7. Returns 0 to indicate successful completion

## Key Code Patterns

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // ... program logic ...
    return 0;
}
```

## Libraries Used

- **`<stdio.h>`** — Standard I/O: `printf()`, `scanf()`, `fgets()`, `FILE` operations
- **`<stdlib.h>`** — Standard library: `malloc()`, `free()`, `atoi()`, `rand()`, `exit()`

## Known Bugs

This file contains deliberate errors. Common categories:
- **Memory bugs**: leaks, double-free, use-after-free
- **Pointer bugs**: null dereference, dangling pointers
- **Logic bugs**: off-by-one, incorrect conditions
- **IO bugs**: unformatted input, buffer overflow

Compile with full warnings and address sanitizer to detect them:
```bash
gcc pointer_basics_buggy.c -o pointer_basics_buggy -std=c11 -Wall -Wextra -Werror -fsanitize=address
```

## Compilation

```bash
cd 06-pointers

# Compile with GCC (debug build)
gcc pointer_basics_buggy.c -o pointer_basics_buggy -std=c11 -Wall -Wextra -g

# Run
./pointer_basics_buggy

# Compile with Clang
clang pointer_basics_buggy.c -o pointer_basics_buggy -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc pointer_basics_buggy.c -o pointer_basics_buggy -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`
- **Library header:** `<stdlib.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
