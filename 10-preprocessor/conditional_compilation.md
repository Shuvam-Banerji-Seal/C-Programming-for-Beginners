# `conditional_compilation.c`

> conditional_compilation.c
Advanced conditional compilation techniques
Topics: Feature flags, debug builds, optimization levels

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `10-preprocessor/conditional_compilation.c` |
| **Type** | C source |
| **Module** | `10-preprocessor` |
| **Lines** | 262 total (193 code, 26 comments) |
| **Libraries** | `stdio.h`, `time.h`, `stdlib.h` |
| **Topics** | Functions |

## What It Does

Demonstrates `#ifdef`, `#ifndef`, `#if`, `#else`, `#elif`, and `#endif` directives. Shows how to write code that compiles differently on various platforms, debug vs release builds, and feature toggles.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (52 calls) to display output to the console
4. Allocates memory dynamically on the heap
5. Makes decisions using conditional statements (3 branches)
6. Iterates using loops (3 loops)
7. Returns 0 to indicate successful completion

## Key Code Patterns

```c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
    // ... program logic ...
    return 0;
}
```

## Libraries Used

- **`<stdio.h>`** — Standard I/O: `printf()`, `scanf()`, `fgets()`, `FILE` operations
- **`<time.h>`** — Time: `time()`, `clock()`, `srand()`, `rand()`
- **`<stdlib.h>`** — Standard library: `malloc()`, `free()`, `atoi()`, `rand()`, `exit()`

## Functions

| Function | Returns | Parameters | Purpose |
|----------|---------|------------|---------|
| `compute()` | `int` | `int n` | See implementation for details |

## Constants & Macros

| Name | Value |
|------|-------|
| `FEATURE_LOGGING` | Defined in source |
| `FEATURE_TIMING` | Defined in source |
| `FEATURE_VALIDATION` | Defined in source |
| `DEBUG_LEVEL` | Defined in source |
| `LOG_ERROR` | Defined in source |
| `LOG_ERROR` | Defined in source |
| `LOG_WARNING` | Defined in source |
| `LOG_WARNING` | Defined in source |
| `LOG_INFO` | Defined in source |
| `LOG_INFO` | Defined in source |
| `LOG_VERBOSE` | Defined in source |
| `LOG_VERBOSE` | Defined in source |
| `START_TIMER` | Defined in source |
| `END_TIMER` | Defined in source |
| `START_TIMER` | Defined in source |
| `END_TIMER` | Defined in source |
| `VALIDATE_RANGE` | Defined in source |
| `VALIDATE_NOT_NULL` | Defined in source |
| `VALIDATE_RANGE` | Defined in source |
| `VALIDATE_NOT_NULL` | Defined in source |
| `VERSION_MAJOR` | Defined in source |
| `VERSION_MINOR` | Defined in source |
| `VERSION_PATCH` | Defined in source |
| `VERSION_STRING` | Defined in source |
| `MAKE_VERSION` | Defined in source |
| `CURRENT_VERSION` | Defined in source |
| `LIKELY` | Defined in source |
| `UNLIKELY` | Defined in source |
| `INLINE` | Defined in source |
| `LIKELY` | Defined in source |
| `UNLIKELY` | Defined in source |
| `INLINE` | Defined in source |
| `MALLOC` | Defined in source |
| `FREE` | Defined in source |
| `MALLOC` | Defined in source |
| `FREE` | Defined in source |
| `ARCH` | Defined in source |
| `ARCH_BITS` | Defined in source |
| `ARCH` | Defined in source |
| `ARCH_BITS` | Defined in source |
| `ARCH` | Defined in source |
| `ARCH_BITS` | Defined in source |
| `ARCH` | Defined in source |
| `ARCH_BITS` | Defined in source |
| `ARCH` | Defined in source |
| `ARCH_BITS` | Defined in source |

## Compilation

```bash
cd 10-preprocessor

# Compile with GCC (debug build)
gcc conditional_compilation.c -o conditional_compilation -std=c11 -Wall -Wextra -g

# Run
./conditional_compilation

# Compile with Clang
clang conditional_compilation.c -o conditional_compilation -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc conditional_compilation.c -o conditional_compilation -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`
- **Library header:** `<time.h>`
- **Library header:** `<stdlib.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
