# `string_operations.c`

> Custom string length

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `05-arrays-and-strings/string_operations.c` |
| **Type** | C source |
| **Module** | `05-arrays-and-strings` |
| **Lines** | 102 total (72 code, 12 comments) |
| **Libraries** | `stdio.h`, `string.h` |
| **Topics** | Strings |

## What It Does

String manipulation in C without `string.h`. Implements `strlen`, `strcpy`, `strcmp`, `strcat`, and other operations from scratch — building deep understanding of how strings work as null-terminated character arrays.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (9 calls) to display output to the console
5. Makes decisions using conditional statements (2 branches)
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

## Functions

| Function | Returns | Parameters | Purpose |
|----------|---------|------------|---------|
| `myStrLen()` | `int` | `char str[]` | See implementation for details |
| `myStrCpy()` | `void` | `char dest[], char src[]` | See implementation for details |
| `myStrCat()` | `void` | `char dest[], char src[]` | See implementation for details |
| `myStrCmp()` | `int` | `char str1[], char str2[]` | See implementation for details |
| `reverseString()` | `void` | `char str[]` | See implementation for details |
| `isPalindrome()` | `int` | `char str[]` | See implementation for details |

## Compilation

```bash
cd 05-arrays-and-strings

# Compile with GCC (debug build)
gcc string_operations.c -o string_operations -std=c11 -Wall -Wextra -g

# Run
./string_operations

# Compile with Clang
clang string_operations.c -o string_operations -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc string_operations.c -o string_operations -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`
- **Library header:** `<string.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
