# `error_handling.c`

> error_handling.c
Demonstrates error handling strategies in C
Topics: errno, perror, strerror, return codes, error propagation,
file I/O errors, memory allocation errors

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `fundamentals/error_handling/error_handling.c` |
| **Type** | C source |
| **Module** | `error_handling` |
| **Lines** | 459 total (272 code, 112 comments) |
| **Libraries** | `stdio.h`, `stdlib.h`, `string.h`, `errno.h`, `limits.h` |
| **Topics** | Functions |

## What It Does

Error handling patterns in C: `errno`, `perror()`, `strerror()`, return codes vs exceptions, and cleanup with `goto` for resource management. C has no exceptions — mastering error handling is critical.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (54 calls) to display output to the console
4. Allocates memory dynamically on the heap
5. Makes decisions using conditional statements (35 branches)
7. Returns 0 to indicate successful completion

## Key Code Patterns

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(void) {
    // ... program logic ...
    return 0;
}
```

## Libraries Used

- **`<stdio.h>`** — Standard I/O: `printf()`, `scanf()`, `fgets()`, `FILE` operations
- **`<stdlib.h>`** — Standard library: `malloc()`, `free()`, `atoi()`, `rand()`, `exit()`
- **`<string.h>`** — String manipulation: `strlen()`, `strcpy()`, `strcmp()`, `strcat()`
- **`<errno.h>`** — Error codes: `errno` variable, error number constants
- **`<limits.h>`** — Integer limits: `INT_MAX`, `LONG_MIN`, `CHAR_BIT`

## Functions

| Function | Returns | Parameters | Purpose |
|----------|---------|------------|---------|
| `safe_divide()` | `int` | `int numerator, int denominator, int *result` | See implementation for details |
| `demonstrate_return_codes()` | `void` | `void` | See implementation for details |
| `demonstrate_errno_and_perror()` | `void` | `void` | See implementation for details |
| `read_file_contents()` | `char *` | `const char *filename` | See implementation for details |
| `demonstrate_file_error_handling()` | `void` | `void` | See implementation for details |
| `create_int_array()` | `int *` | `size_t count` | See implementation for details |
| `resize_int_array()` | `int *` | `int *arr, size_t old_count, size_t new_count` | See implementation for details |
| `demonstrate_memory_error_handling()` | `void` | `void` | See implementation for details |
| `read_sensor_value()` | `int` | `int sensor_id, double *value` | See implementation for details |
| `compute_average_reading()` | `int` | `int sensor_id, int num_readings, double *average` | See implementation for details |
| `demonstrate_error_propagation()` | `void` | `void` | See implementation for details |

## Constants & Macros

| Name | Value |
|------|-------|
| `SUCCESS` | Defined in source |
| `ERR_NULL_PTR` | Defined in source |
| `ERR_OUT_OF_RANGE` | Defined in source |
| `ERR_OVERFLOW` | Defined in source |

## Compilation

```bash
cd fundamentals/error_handling

# Compile with GCC (debug build)
gcc error_handling.c -o error_handling -std=c11 -Wall -Wextra -g

# Run
./error_handling

# Compile with Clang
clang error_handling.c -o error_handling -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc error_handling.c -o error_handling -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`
- **Library header:** `<stdlib.h>`
- **Library header:** `<string.h>`
- **Library header:** `<errno.h>`
- **Library header:** `<limits.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
