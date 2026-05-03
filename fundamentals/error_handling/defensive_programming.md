# defensive_programming.c

defensive_programming.c
Demonstrates defensive programming techniques in C

Topics: assert, input validation, bounds checking, NULL guards,
safe string operations

## Overview

- **File:** `fundamentals/error_handling/defensive_programming.c`
- **Language:** C
- **Module:** `error_handling`

## Key Concepts

This file demonstrates essential C programming concepts including:
- Standard input/output operations using `printf` and `scanf`
- Standard library functions (`malloc`, `free`, `atoi`, etc.)
- String manipulation functions
- Runtime assertions for debugging

## Functions

- `errors()`
- `factorial()`
- `array_get()`
- `demonstrate_assert()`
- `assert()`
- `VALID()`
- `validate_username()`
- `validate_age()`
- `demonstrate_input_validation()`
- `printing()`
- `safe_array_destroy()`
- `safe_array_set()`
- `safe_array_get()`
- `demonstrate_bounds_checking()`
- `set()`
- `get()`
- `safe_strlen()`
- `strlen()`
- `safe_print_person()`
- `demonstrate_null_guards()`
- `record()`
- `strcpy()`
- `strcat()`
- `safe_string_copy()`
- `safe_string_concat()`
- `demonstrate_safe_strings()`
- `snprintf()`
- `chars()`

## Compilation

```bash
# Navigate to the module directory
cd fundamentals/error_handling

# Compile
gcc defensive_programming.c -o defensive_programming -std=c11 -Wall -Wextra

# Run
./defensive_programming
```

## Usage

Run the compiled program to see the demonstrated concepts in action.
