# `compilation_demo.c`

> compilation_demo.c
A program to demonstrate the compilation process
Compile this with:
gcc -E compilation_demo.c -o compilation_demo.i  (preprocessing)
gcc -S compilation_demo.c -o compilation_demo.s  (compilation to assembly)
gcc -c compilation_demo.c -o compilation_demo.o  (assembly to object)
gcc compilation_demo.o -o compilation_demo       (linking)
Or simply:
gcc compilation_demo.c -o compilation_demo

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `01-basics/compilation_demo.c` |
| **Type** | C source |
| **Module** | `01-basics` |
| **Lines** | 34 total (12 code, 13 comments) |
| **Libraries** | `stdio.h` |
| **Topics** | Compilation Process |

## What It Does

Shows the four stages of C compilation (preprocessing, compilation, assembly, linking) by examining intermediate files. Demonstrates how to use compiler flags like `-E`, `-S`, `-c` to observe each stage.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (4 calls) to display output to the console
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

## Constants & Macros

| Name | Value |
|------|-------|
| `PI` | Defined in source |
| `SQUARE` | Defined in source |

## Compilation

```bash
cd 01-basics

# Compile with GCC (debug build)
gcc compilation_demo.c -o compilation_demo -std=c11 -Wall -Wextra -g

# Run
./compilation_demo

# Compile with Clang
clang compilation_demo.c -o compilation_demo -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc compilation_demo.c -o compilation_demo -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
