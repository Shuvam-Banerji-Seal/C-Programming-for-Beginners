# defensive_programming.c

> defensive_programming.c
Demonstrates defensive programming techniques in C
Topics: assert, input validation, bounds checking, NULL guards,
safe string operations

## Overview

- **File:** `fundamentals/error_handling/defensive_programming.c`
- **Language:** C source
- **Module:** `error_handling`
- **Lines:** 520
- **Libraries:** `stdio.h`, `stdlib.h`, `string.h`, `assert.h`, `ctype.h`

## Concepts

- Standard I/O: `printf`, `scanf` for console input/output
- Standard library: memory allocation (`malloc`/`free`), conversions (`atoi`), exit codes
- String manipulation: `strlen`, `strcpy`, `strcmp`, `strcat`
- Runtime assertions for debugging program invariants
- Pointer operations: declaration, dereferencing (`*`), address-of (`&`), arithmetic
- Structures: defining structs, member access (`.`/`->`), nested structs
- Heap memory allocation: `malloc`/`calloc`/`realloc` and `free`
- Type aliasing with `typedef` for cleaner type definitions
- Memory layout analysis using `sizeof` operator

## Functions

### `factorial()`

```c
unsigned long factorial(int n);
```

### `array_get()`

```c
int array_get(const int *arr, size_t size, size_t index);
```

### `demonstrate_assert()`

```c
void demonstrate_assert(void);
```

### `validate_username()`

```c
int validate_username(const char *username);
```

### `validate_age()`

```c
int validate_age(int age);
```

### `demonstrate_input_validation()`

```c
void demonstrate_input_validation(void);
```

### `safe_array_create()`

```c
SafeArray * safe_array_create(size_t capacity);
```

### `safe_array_destroy()`

```c
void safe_array_destroy(SafeArray *arr);
```

### `safe_array_set()`

```c
int safe_array_set(SafeArray *arr, size_t index, int value);
```

### `safe_array_get()`

```c
int safe_array_get(const SafeArray *arr, size_t index, int *out_value);
```

### `demonstrate_bounds_checking()`

```c
void demonstrate_bounds_checking(void);
```

### `safe_strlen()`

```c
size_t safe_strlen(const char *str);
```

### `safe_print_person()`

```c
void safe_print_person(const Person *p);
```

### `demonstrate_null_guards()`

```c
void demonstrate_null_guards(void);
```

### `safe_string_copy()`

```c
int safe_string_copy(char *dest, size_t dest_size, const char *src);
```

### `safe_string_concat()`

```c
int safe_string_concat(char *dest, size_t dest_size, const char *src);
```

### `demonstrate_safe_strings()`

```c
void demonstrate_safe_strings(void);
```

## Compilation

```bash
cd fundamentals/error_handling
gcc defensive_programming.c -o defensive_programming -std=c11 -Wall -Wextra
./defensive_programming
```
