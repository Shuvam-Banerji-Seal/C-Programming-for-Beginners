# `advanced_preprocessor.c`

> advanced_preprocessor.c
Advanced preprocessor directives and macros
Topics: Variadic macros, token pasting, stringification, X-macros

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `10-preprocessor/advanced_preprocessor.c` |
| **Type** | C source |
| **Module** | `10-preprocessor` |
| **Lines** | 246 total (173 code, 33 comments) |
| **Libraries** | `stdio.h`, `string.h` |
| **Topics** | Preprocessor, Typedef, Enum |

## What It Does

Explores the C preprocessor: `#define` macros (with and without parameters), `#include`, `#ifdef`/`#ifndef` for conditional compilation, `#pragma`, and the `##` token pasting operator.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (54 calls) to display output to the console
5. Makes decisions using conditional statements (1 branches)
6. Iterates using loops (3 loops)
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

## Constants & Macros

| Name | Value |
|------|-------|
| `CONCAT` | Defined in source |
| `VAR_NAME` | Defined in source |
| `TO_STRING` | Defined in source |
| `STRINGIFY` | Defined in source |
| `PRINT_ARGS` | Defined in source |
| `DEBUG_PRINT` | Defined in source |
| `MIN` | Defined in source |
| `MAX` | Defined in source |
| `ARRAY_SIZE` | Defined in source |
| `FOR_EACH` | Defined in source |
| `CHECK_NULL` | Defined in source |
| `COLOR_TABLE` | Defined in source |
| `X` | Defined in source |
| `X` | Defined in source |
| `PLATFORM` | Defined in source |
| `PATH_SEPARATOR` | Defined in source |
| `PLATFORM` | Defined in source |
| `PATH_SEPARATOR` | Defined in source |
| `PLATFORM` | Defined in source |
| `PATH_SEPARATOR` | Defined in source |
| `PLATFORM` | Defined in source |
| `PATH_SEPARATOR` | Defined in source |
| `COMPILER` | Defined in source |
| `COMPILER_VERSION` | Defined in source |
| `COMPILER` | Defined in source |
| `COMPILER_VERSION` | Defined in source |
| `COMPILER` | Defined in source |
| `COMPILER_VERSION` | Defined in source |
| `COMPILER` | Defined in source |
| `COMPILER_VERSION` | Defined in source |
| `STATIC_ASSERT` | Defined in source |
| `SWAP` | Defined in source |
| `SET_BIT` | Defined in source |
| `CLEAR_BIT` | Defined in source |
| `TOGGLE_BIT` | Defined in source |
| `CHECK_BIT` | Defined in source |
| `PRINT_ARRAY` | Defined in source |
| `SQRT` | Defined in source |
| `SQRT` | Defined in source |

## Compilation

```bash
cd 10-preprocessor

# Compile with GCC (debug build)
gcc advanced_preprocessor.c -o advanced_preprocessor -std=c11 -Wall -Wextra -g

# Run
./advanced_preprocessor

# Compile with Clang
clang advanced_preprocessor.c -o advanced_preprocessor -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc advanced_preprocessor.c -o advanced_preprocessor -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`
- **Library header:** `<string.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
