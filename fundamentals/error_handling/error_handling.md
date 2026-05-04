# error_handling.c

> error_handling.c
Demonstrates error handling strategies in C
Topics: errno, perror, strerror, return codes, error propagation,
file I/O errors, memory allocation errors

## Overview

- **File:** `fundamentals/error_handling/error_handling.c`
- **Language:** C source
- **Module:** `error_handling`
- **Lines:** 459
- **Libraries:** `stdio.h`, `stdlib.h`, `string.h`, `errno.h`, `limits.h`

## Concepts

- Standard I/O: `printf`, `scanf` for console input/output
- Standard library: memory allocation (`malloc`/`free`), conversions (`atoi`), exit codes
- String manipulation: `strlen`, `strcpy`, `strcmp`, `strcat`
- Error handling via `errno` and `perror`
- File I/O: open, read, write, close files in text and binary modes
- Pointer operations: declaration, dereferencing (`*`), address-of (`&`), arithmetic
- Heap memory allocation: `malloc`/`calloc`/`realloc` and `free`
- Memory layout analysis using `sizeof` operator

## Functions

### `safe_divide()`

```c
int safe_divide(int numerator, int denominator, int *result);
```

### `demonstrate_return_codes()`

```c
void demonstrate_return_codes(void);
```

### `demonstrate_errno_and_perror()`

```c
void demonstrate_errno_and_perror(void);
```

### `read_file_contents()`

```c
char * read_file_contents(const char *filename);
```

### `demonstrate_file_error_handling()`

```c
void demonstrate_file_error_handling(void);
```

### `create_int_array()`

```c
int * create_int_array(size_t count);
```

### `resize_int_array()`

```c
int * resize_int_array(int *arr, size_t old_count, size_t new_count);
```

### `demonstrate_memory_error_handling()`

```c
void demonstrate_memory_error_handling(void);
```

### `read_sensor_value()`

```c
int read_sensor_value(int sensor_id, double *value);
```

### `compute_average_reading()`

```c
int compute_average_reading(int sensor_id, int num_readings, double *average);
```

### `demonstrate_error_propagation()`

```c
void demonstrate_error_propagation(void);
```

## Compilation

```bash
cd fundamentals/error_handling
gcc error_handling.c -o error_handling -std=c11 -Wall -Wextra
./error_handling
```
