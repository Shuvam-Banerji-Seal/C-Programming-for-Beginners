# `hello_user.c`

> hello_user.c
A program that greets the user by name

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `01-basics/hello_user.c` |
| **Type** | C source |
| **Module** | `01-basics` |
| **Lines** | 22 total (7 code, 7 comments) |
| **Libraries** | `stdio.h` |
| **Topics** | User Input |

## What It Does

This program extends Hello World by accepting user input. It demonstrates how to read strings and integers from the user using `scanf()` and `fgets()`, and how to format output with `printf()`.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (2 calls) to display output to the console
3. Uses `scanf()` (1 calls) to read user input
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
gcc hello_user.c -o hello_user -std=c11 -Wall -Wextra -g

# Run
./hello_user

# Compile with Clang
clang hello_user.c -o hello_user -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc hello_user.c -o hello_user -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
