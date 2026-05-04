# dynamic_memory.c

> dynamic_memory.c
Demonstrates dynamic memory allocation in C
Topics: malloc, calloc, realloc, free, memory leaks

## Overview

- **File:** `07-memory-management/dynamic_memory.c`
- **Language:** C source
- **Module:** `07-memory-management`
- **Lines:** 139
- **Libraries:** `stdio.h`, `stdlib.h`, `string.h`

## Concepts

- Standard I/O: `printf`, `scanf` for console input/output
- Standard library: memory allocation (`malloc`/`free`), conversions (`atoi`), exit codes
- String manipulation: `strlen`, `strcpy`, `strcmp`, `strcat`
- Pointer operations: declaration, dereferencing (`*`), address-of (`&`), arithmetic
- Heap memory allocation: `malloc`/`calloc`/`realloc` and `free`
- Memory layout analysis using `sizeof` operator

## Compilation

```bash
cd 07-memory-management
gcc dynamic_memory.c -o dynamic_memory -std=c11 -Wall -Wextra
./dynamic_memory
```
