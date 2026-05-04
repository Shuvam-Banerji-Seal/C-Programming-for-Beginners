# `structures_demo.c`

> structures_demo.c
Demonstrates structures in C
Topics: struct definition, initialization, nested structures, arrays of structures

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `08-structures-unions/structures_demo.c` |
| **Type** | C source |
| **Module** | `08-structures-unions` |
| **Lines** | 80 total (50 code, 14 comments) |
| **Libraries** | `stdio.h`, `string.h` |
| **Topics** | Structures, Typedef |

## What It Does

Introduces `struct` for grouping related data. Covers definition, member access, nested structs, arrays of structs, passing structs to functions, and typedef for cleaner syntax.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (13 calls) to display output to the console
7. Returns 0 to indicate successful completion

## Key Code Patterns

```c
#include <stdio.h>
#include <string.h>

int main(void) {
    // ... program logic ...
    return 0;
}
```

## Libraries Used

- **`<stdio.h>`** — Standard I/O: `printf()`, `scanf()`, `fgets()`, `FILE` operations
- **`<string.h>`** — String manipulation: `strlen()`, `strcpy()`, `strcmp()`, `strcat()`

## Compilation

```bash
cd 08-structures-unions

# Compile with GCC (debug build)
gcc structures_demo.c -o structures_demo -std=c11 -Wall -Wextra -g

# Run
./structures_demo

# Compile with Clang
clang structures_demo.c -o structures_demo -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc structures_demo.c -o structures_demo -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`
- **Library header:** `<string.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
