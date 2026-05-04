# `defensive_programming.c`

> defensive_programming.c
Demonstrates defensive programming techniques in C
Topics: assert, input validation, bounds checking, NULL guards,
safe string operations

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `fundamentals/error_handling/defensive_programming.c` |
| **Type** | C source |
| **Module** | `error_handling` |
| **Lines** | 520 total (315 code, 110 comments) |
| **Libraries** | `stdio.h`, `stdlib.h`, `string.h`, `assert.h`, `ctype.h` |
| **Topics** | Typedef |

## What It Does

Defensive programming techniques: input validation, boundary checking, error return codes, assertions, and safe coding patterns. Writing C code that gracefully handles unexpected conditions.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (61 calls) to display output to the console
4. Allocates memory dynamically on the heap
5. Makes decisions using conditional statements (24 branches)
7. Returns 0 to indicate successful completion

## Key Code Patterns

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main(void) {
    // ... program logic ...
    return 0;
}
```

## Libraries Used

- **`<stdio.h>`** — Standard I/O: `printf()`, `scanf()`, `fgets()`, `FILE` operations
- **`<stdlib.h>`** — Standard library: `malloc()`, `free()`, `atoi()`, `rand()`, `exit()`
- **`<string.h>`** — String manipulation: `strlen()`, `strcpy()`, `strcmp()`, `strcat()`
- **`<assert.h>`** — Debugging: `assert()` macro for runtime invariants
- **`<ctype.h>`** — Character handling: `isalpha()`, `isdigit()`, `toupper()`

## Functions

| Function | Returns | Parameters | Purpose |
|----------|---------|------------|---------|
| `factorial()` | `unsigned long` | `int n` | See implementation for details |
| `array_get()` | `int` | `const int *arr, size_t size, size_t index` | See implementation for details |
| `demonstrate_assert()` | `void` | `void` | See implementation for details |
| `validate_username()` | `int` | `const char *username` | See implementation for details |
| `validate_age()` | `int` | `int age` | See implementation for details |
| `demonstrate_input_validation()` | `void` | `void` | See implementation for details |
| `safe_array_create()` | `SafeArray *` | `size_t capacity` | See implementation for details |
| `safe_array_destroy()` | `void` | `SafeArray *arr` | See implementation for details |
| `safe_array_set()` | `int` | `SafeArray *arr, size_t index, int value` | See implementation for details |
| `safe_array_get()` | `int` | `const SafeArray *arr, size_t index, int *out_value` | See implementation for details |
| `demonstrate_bounds_checking()` | `void` | `void` | See implementation for details |
| `safe_strlen()` | `size_t` | `const char *str` | See implementation for details |
| `safe_print_person()` | `void` | `const Person *p` | See implementation for details |
| `demonstrate_null_guards()` | `void` | `void` | See implementation for details |
| `safe_string_copy()` | `int` | `char *dest, size_t dest_size, const char *src` | See implementation for details |
| `safe_string_concat()` | `int` | `char *dest, size_t dest_size, const char *src` | See implementation for details |
| `demonstrate_safe_strings()` | `void` | `void` | See implementation for details |

## Constants & Macros

| Name | Value |
|------|-------|
| `VALID` | Defined in source |
| `INVALID_NULL` | Defined in source |
| `INVALID_EMPTY` | Defined in source |
| `INVALID_LENGTH` | Defined in source |
| `INVALID_CHARS` | Defined in source |
| `INVALID_RANGE` | Defined in source |

## Compilation

```bash
cd fundamentals/error_handling

# Compile with GCC (debug build)
gcc defensive_programming.c -o defensive_programming -std=c11 -Wall -Wextra -g

# Run
./defensive_programming

# Compile with Clang
clang defensive_programming.c -o defensive_programming -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc defensive_programming.c -o defensive_programming -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`
- **Library header:** `<stdlib.h>`
- **Library header:** `<string.h>`
- **Library header:** `<assert.h>`
- **Library header:** `<ctype.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
