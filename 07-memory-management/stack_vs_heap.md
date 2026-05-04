# stack_vs_heap.c

> stack_vs_heap.c
Demonstrates the difference between stack and heap memory
Topics: Stack allocation, heap allocation, scope, lifetime

## Overview

- **File:** `07-memory-management/stack_vs_heap.c`
- **Language:** C source
- **Module:** `07-memory-management`
- **Lines:** 150
- **Libraries:** `stdio.h`, `stdlib.h`

## Concepts

- Standard I/O: `printf`, `scanf` for console input/output
- Standard library: memory allocation (`malloc`/`free`), conversions (`atoi`), exit codes
- Pointer operations: declaration, dereferencing (`*`), address-of (`&`), arithmetic
- Structures: defining structs, member access (`.`/`->`), nested structs
- Heap memory allocation: `malloc`/`calloc`/`realloc` and `free`
- Memory layout analysis using `sizeof` operator

## Functions

### `stack_example()`

```c
void stack_example();
```

## Compilation

```bash
cd 07-memory-management
gcc stack_vs_heap.c -o stack_vs_heap -std=c11 -Wall -Wextra
./stack_vs_heap
```
