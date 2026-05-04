# segfault_example.c

> segfault_example.c
Example program that demonstrates common segmentation faults
Use GDB to find and understand the crashes

## Overview

- **File:** `13-debugging-gdb/segfault_example.c`
- **Language:** C source
- **Module:** `13-debugging-gdb`
- **Lines:** 67
- **Libraries:** `stdio.h`, `stdlib.h`

## Concepts

- Standard I/O: `printf`, `scanf` for console input/output
- Standard library: memory allocation (`malloc`/`free`), conversions (`atoi`), exit codes
- Pointer operations: declaration, dereferencing (`*`), address-of (`&`), arithmetic
- Heap memory allocation: `malloc`/`calloc`/`realloc` and `free`
- Memory layout analysis using `sizeof` operator

## Functions

### `example1_null_pointer()`

```c
void example1_null_pointer();
```

### `example2_buffer_overflow()`

```c
void example2_buffer_overflow();
```

### `example3_use_after_free()`

```c
void example3_use_after_free();
```

### `example4_stack_overflow()`

```c
void example4_stack_overflow();
```

## Compilation

```bash
cd 13-debugging-gdb
gcc segfault_example.c -o segfault_example -std=c11 -Wall -Wextra
./segfault_example
```
