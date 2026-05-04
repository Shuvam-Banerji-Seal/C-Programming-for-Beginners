# pointers_functions.c

> pointers_functions.c
Demonstrates pointers with functions
Topics: Pass by value vs reference, returning pointers, function pointers

## Overview

- **File:** `06-pointers/pointers_functions.c`
- **Language:** C source
- **Module:** `06-pointers`
- **Lines:** 168
- **Libraries:** `stdio.h`, `stdlib.h`

## Concepts

- Standard I/O: `printf`, `scanf` for console input/output
- Standard library: memory allocation (`malloc`/`free`), conversions (`atoi`), exit codes
- Pointer operations: declaration, dereferencing (`*`), address-of (`&`), arithmetic
- Heap memory allocation: `malloc`/`calloc`/`realloc` and `free`
- Memory layout analysis using `sizeof` operator

## Functions

### `increment_value()`

```c
void increment_value(int x);
```

### `increment_reference()`

```c
void increment_reference(int *x);
```

### `swap()`

```c
void swap(int *a, int *b);
```

### `add()`

```c
int add(int a, int b);
```

### `subtract()`

```c
int subtract(int a, int b);
```

### `multiply()`

```c
int multiply(int a, int b);
```

### `print_array()`

```c
void print_array(int *arr, int size);
```

### `double_array_values()`

```c
void double_array_values(int *arr, int size);
```

## Compilation

```bash
cd 06-pointers
gcc pointers_functions.c -o pointers_functions -std=c11 -Wall -Wextra
./pointers_functions
```
