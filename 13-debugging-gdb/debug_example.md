# debug_example.c

> debug_example.c
Example program for GDB debugging practice
This program has a bug - can you find it with GDB?

## Overview

- **File:** `13-debugging-gdb/debug_example.c`
- **Language:** C source
- **Module:** `13-debugging-gdb`
- **Lines:** 51
- **Libraries:** `stdio.h`

## Concepts

- Standard I/O: `printf`, `scanf` for console input/output
- Pointer operations: declaration, dereferencing (`*`), address-of (`&`), arithmetic
- Memory layout analysis using `sizeof` operator

## Functions

### `factorial()`

```c
int factorial(int n);
```

### `sum_array()`

```c
int sum_array(int *arr, int size);
```

## Compilation

```bash
cd 13-debugging-gdb
gcc debug_example.c -o debug_example -std=c11 -Wall -Wextra
./debug_example
```
