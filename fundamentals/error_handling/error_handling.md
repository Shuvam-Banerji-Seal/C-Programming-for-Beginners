# error_handling.c

error_handling.c
Demonstrates error handling strategies in C

Topics: errno, perror, strerror, return codes, error propagation,
file I/O errors, memory allocation errors

## Overview

- **File:** `fundamentals/error_handling/error_handling.c`
- **Language:** C
- **Module:** `error_handling`

## Key Concepts

This file demonstrates essential C programming concepts including:
- Standard input/output operations using `printf` and `scanf`
- Standard library functions (`malloc`, `free`, `atoi`, etc.)
- String manipulation functions

## Functions

- `safe_divide()`
- `demonstrate_return_codes()`
- `perror()`
- `demonstrate_errno_and_perror()`
- `strerror()`
- `buffer()`
- `demonstrate_file_error_handling()`
- `NULL()`
- `realloc()`
- `handling()`
- `demonstrate_memory_error_handling()`
- `read_sensor_value()`
- `compute_average_reading()`
- `demonstrate_error_propagation()`

## Compilation

```bash
# Navigate to the module directory
cd fundamentals/error_handling

# Compile
gcc error_handling.c -o error_handling -std=c11 -Wall -Wextra

# Run
./error_handling
```

## Usage

Run the compiled program to see the demonstrated concepts in action.
