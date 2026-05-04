# memory_buggy.c

> memory_buggy.c
DELIBERATELY BUGGY CODE - For learning purposes
Common memory management mistakes

## Overview

- **File:** `07-memory-management/memory_buggy.c`
- **Language:** C source
- **Module:** `07-memory-management`
- **Lines:** 149
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
gcc memory_buggy.c -o memory_buggy -std=c11 -Wall -Wextra
./memory_buggy
```
