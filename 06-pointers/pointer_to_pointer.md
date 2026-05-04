# pointer_to_pointer.c

> pointer_to_pointer.c
Demonstrates pointer to pointer (double pointers)
Topics: Double pointers, triple pointers, use cases

## Overview

- **File:** `06-pointers/pointer_to_pointer.c`
- **Language:** C source
- **Module:** `06-pointers`
- **Lines:** 151
- **Libraries:** `stdio.h`, `stdlib.h`, `string.h`

## Concepts

- Standard I/O: `printf`, `scanf` for console input/output
- Standard library: memory allocation (`malloc`/`free`), conversions (`atoi`), exit codes
- String manipulation: `strlen`, `strcpy`, `strcmp`, `strcat`
- Pointer operations: declaration, dereferencing (`*`), address-of (`&`), arithmetic
- Heap memory allocation: `malloc`/`calloc`/`realloc` and `free`
- Memory layout analysis using `sizeof` operator

## Functions

### `allocate_memory()`

```c
void allocate_memory(int **ptr, int value);
```

### `swap_pointers()`

```c
void swap_pointers(int **p1, int **p2);
```

## Compilation

```bash
cd 06-pointers
gcc pointer_to_pointer.c -o pointer_to_pointer -std=c11 -Wall -Wextra
./pointer_to_pointer
```
