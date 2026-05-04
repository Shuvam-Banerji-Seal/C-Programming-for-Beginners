# `memory_buggy.c`

> memory_buggy.c
DELIBERATELY BUGGY CODE - For learning purposes
Common memory management mistakes

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `07-memory-management/memory_buggy.c` |
| **Type** | C source |
| **Module** | `07-memory-management` |
| **Lines** | 149 total (91 code, 37 comments) |
| **Libraries** | `stdio.h`, `stdlib.h`, `string.h` |
| **Topics** | Buggy Example |

## What It Does

This file contains **deliberately introduced bugs** for educational purposes. Study the code, identify the errors, compile to see what warnings/errors GCC and Clang produce, then fix them. This is an essential learning technique — understanding what *not* to do.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (39 calls) to display output to the console
4. Allocates memory dynamically on the heap
5. Makes decisions using conditional statements (10 branches)
7. Returns 0 to indicate successful completion

## Key Code Patterns

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // ... program logic ...
    return 0;
}
```

## Libraries Used

- **`<stdio.h>`** — Standard I/O: `printf()`, `scanf()`, `fgets()`, `FILE` operations
- **`<stdlib.h>`** — Standard library: `malloc()`, `free()`, `atoi()`, `rand()`, `exit()`
- **`<string.h>`** — String manipulation: `strlen()`, `strcpy()`, `strcmp()`, `strcat()`

## Known Bugs

This file contains deliberate errors. Common categories:
- **Memory bugs**: leaks, double-free, use-after-free
- **Pointer bugs**: null dereference, dangling pointers
- **Logic bugs**: off-by-one, incorrect conditions
- **IO bugs**: unformatted input, buffer overflow

Compile with full warnings and address sanitizer to detect them:
```bash
gcc memory_buggy.c -o memory_buggy -std=c11 -Wall -Wextra -Werror -fsanitize=address
```

## Compilation

```bash
cd 07-memory-management

# Compile with GCC (debug build)
gcc memory_buggy.c -o memory_buggy -std=c11 -Wall -Wextra -g

# Run
./memory_buggy

# Compile with Clang
clang memory_buggy.c -o memory_buggy -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc memory_buggy.c -o memory_buggy -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`
- **Library header:** `<stdlib.h>`
- **Library header:** `<string.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
