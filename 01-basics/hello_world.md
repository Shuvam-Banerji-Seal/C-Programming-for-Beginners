# `hello_world.c`

> hello_world.c
The classic "Hello, World!" program
This is your first C program!

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `01-basics/hello_world.c` |
| **Type** | C source |
| **Module** | `01-basics` |
| **Lines** | 17 total (4 code, 8 comments) |
| **Libraries** | `stdio.h` |
| **Topics** | First Program |

## What It Does

This is the classic first C program. It prints a greeting to the console, demonstrating the basic structure of a C program: `#include` directives, the `main()` function, `printf()` for output, and `return` for exit status.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (1 calls) to display output to the console
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
cd 01-basics

# Compile with GCC (debug build)
gcc hello_world.c -o hello_world -std=c11 -Wall -Wextra -g

# Run
./hello_world

# Compile with Clang
clang hello_world.c -o hello_world -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc hello_world.c -o hello_world -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
