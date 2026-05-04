# `advanced_strings.c`

> advanced_strings.c
Advanced string algorithms and manipulation
Topics: Pattern matching, string tokenization, anagrams, palindromes

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `05-arrays-and-strings/advanced_strings.c` |
| **Type** | C source |
| **Module** | `05-arrays-and-strings` |
| **Lines** | 267 total (199 code, 28 comments) |
| **Libraries** | `stdio.h`, `string.h`, `ctype.h`, `stdbool.h` |
| **Topics** | Strings |

## What It Does

String manipulation in C without `string.h`. Implements `strlen`, `strcpy`, `strcmp`, `strcat`, and other operations from scratch — building deep understanding of how strings work as null-terminated character arrays.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (31 calls) to display output to the console
5. Makes decisions using conditional statements (13 branches)
7. Returns 0 to indicate successful completion

## Key Code Patterns

```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {
    // ... program logic ...
    return 0;
}
```

## Libraries Used

- **`<stdio.h>`** — Standard I/O: `printf()`, `scanf()`, `fgets()`, `FILE` operations
- **`<string.h>`** — String manipulation: `strlen()`, `strcpy()`, `strcmp()`, `strcat()`
- **`<ctype.h>`** — Character handling: `isalpha()`, `isdigit()`, `toupper()`
- **`<stdbool.h>`** — Boolean type: `bool`, `true`, `false` (C99+)

## Functions

| Function | Returns | Parameters | Purpose |
|----------|---------|------------|---------|
| `isPalindrome()` | `bool` | `const char *str` | See implementation for details |
| `areAnagrams()` | `bool` | `const char *str1, const char *str2` | See implementation for details |
| `reverseWords()` | `void` | `char *str` | See implementation for details |
| `patternMatch()` | `int` | `const char *text, const char *pattern` | See implementation for details |
| `countOccurrences()` | `int` | `const char *text, const char *pattern` | See implementation for details |
| `removeDuplicates()` | `void` | `char *str` | See implementation for details |
| `longestCommonPrefix()` | `void` | `char *strings[], int count, char *result` | See implementation for details |
| `runLengthEncode()` | `void` | `const char *str, char *encoded` | See implementation for details |
| `demonstrateTokenization()` | `void` | `` | See implementation for details |

## Compilation

```bash
cd 05-arrays-and-strings

# Compile with GCC (debug build)
gcc advanced_strings.c -o advanced_strings -std=c11 -Wall -Wextra -g

# Run
./advanced_strings

# Compile with Clang
clang advanced_strings.c -o advanced_strings -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc advanced_strings.c -o advanced_strings -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`
- **Library header:** `<string.h>`
- **Library header:** `<ctype.h>`
- **Library header:** `<stdbool.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
