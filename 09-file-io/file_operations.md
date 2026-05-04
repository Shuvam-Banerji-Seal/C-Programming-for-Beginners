# file_operations.c

> file_operations.c
Demonstrates file I/O operations in C
Topics: fopen, fclose, fprintf, fscanf, fread, fwrite

## Overview

- **File:** `09-file-io/file_operations.c`
- **Language:** C source
- **Module:** `09-file-io`
- **Lines:** 68
- **Libraries:** `stdio.h`, `stdlib.h`, `string.h`

## Concepts

- Standard I/O: `printf`, `scanf` for console input/output
- Standard library: memory allocation (`malloc`/`free`), conversions (`atoi`), exit codes
- String manipulation: `strlen`, `strcpy`, `strcmp`, `strcat`
- File I/O: open, read, write, close files in text and binary modes
- Pointer operations: declaration, dereferencing (`*`), address-of (`&`), arithmetic
- Memory layout analysis using `sizeof` operator

## Compilation

```bash
cd 09-file-io
gcc file_operations.c -o file_operations -std=c11 -Wall -Wextra
./file_operations
```
