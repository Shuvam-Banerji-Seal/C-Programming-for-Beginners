# `pointer_basics.c`

> pointer_basics.c
Introduction to pointers in C
Topics: Pointer declaration, address-of (&), dereference (*), NULL pointers

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `06-pointers/pointer_basics.c` |
| **Type** | C source |
| **Module** | `06-pointers` |
| **Lines** | 105 total (65 code, 21 comments) |
| **Libraries** | `stdio.h`, `stddef.h` |
| **Topics** | Pointer Basics |

## What It Does

Introduces pointers — one of C's most powerful and error-prone features. Covers declaration, initialization with `&` (address-of), dereferencing with `*`, NULL pointers, and why pointers are essential for systems programming.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (37 calls) to display output to the console
5. Makes decisions using conditional statements (1 branches)
7. Returns 0 to indicate successful completion

## Key Code Patterns

```c
#include <stdio.h>
#include <stddef.h>

int main(void) {
    // ... program logic ...
    return 0;
}
```

## Libraries Used

- **`<stdio.h>`** — Standard I/O: `printf()`, `scanf()`, `fgets()`, `FILE` operations
- **`<stddef.h>`** — Standard definitions: `NULL`, `size_t`, `ptrdiff_t`

## Compilation

```bash
cd 06-pointers

# Compile with GCC (debug build)
gcc pointer_basics.c -o pointer_basics -std=c11 -Wall -Wextra -g

# Run
./pointer_basics

# Compile with Clang
clang pointer_basics.c -o pointer_basics -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc pointer_basics.c -o pointer_basics -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`
- **Library header:** `<stddef.h>`
- **Buggy version:** [`pointer_basics_buggy.c`](pointer_basics_buggy.c) (learn from common mistakes)

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
