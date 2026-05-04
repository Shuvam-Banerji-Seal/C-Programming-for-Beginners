# `recursion_examples.c`

> Factorial

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `04-functions/recursion_examples.c` |
| **Type** | C source |
| **Module** | `04-functions` |
| **Lines** | 117 total (81 code, 16 comments) |
| **Libraries** | `stdio.h` |
| **Topics** | Recursion |

## What It Does

Shows recursive programming patterns with classic examples: factorial, Fibonacci, tower of Hanoi, and tree traversal. Explains the call stack, base cases, and when to prefer iteration over recursion.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (29 calls) to display output to the console
5. Makes decisions using conditional statements (9 branches)
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
| `factorial()` | `int` | `int n` | See implementation for details |
| `fibonacci()` | `int` | `int n` | See implementation for details |
| `sumOfDigits()` | `int` | `int n` | See implementation for details |
| `power()` | `int` | `int base, int exp` | See implementation for details |
| `gcd()` | `int` | `int a, int b` | See implementation for details |
| `printBinary()` | `void` | `int n` | See implementation for details |
| `towerOfHanoi()` | `void` | `int n, char from, char to, char aux` | See implementation for details |
| `isPalindrome()` | `int` | `char str[], int start, int end` | See implementation for details |

## Compilation

```bash
cd 04-functions

# Compile with GCC (debug build)
gcc recursion_examples.c -o recursion_examples -std=c11 -Wall -Wextra -g

# Run
./recursion_examples

# Compile with Clang
clang recursion_examples.c -o recursion_examples -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc recursion_examples.c -o recursion_examples -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
