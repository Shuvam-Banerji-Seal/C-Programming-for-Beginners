# pointer_basics_buggy.c

> pointer_basics_buggy.c
DELIBERATELY BUGGY CODE - For learning purposes
This file contains common pointer mistakes.
Each bug is explained with comments.

## Overview

- **File:** `06-pointers/pointer_basics_buggy.c`
- **Language:** C source
- **Module:** `06-pointers`
- **Lines:** 142
- **Libraries:** `stdio.h`, `stdlib.h`

## Concepts

- Standard I/O: `printf`, `scanf` for console input/output
- Standard library: memory allocation (`malloc`/`free`), conversions (`atoi`), exit codes
- Pointer operations: declaration, dereferencing (`*`), address-of (`&`), arithmetic
- Heap memory allocation: `malloc`/`calloc`/`realloc` and `free`
- Memory layout analysis using `sizeof` operator

## Compilation

```bash
cd 06-pointers
gcc pointer_basics_buggy.c -o pointer_basics_buggy -std=c11 -Wall -Wextra
./pointer_basics_buggy
```
