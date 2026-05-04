# `file_operations.c`

> file_operations.c
Demonstrates file I/O operations in C
Topics: fopen, fclose, fprintf, fscanf, fread, fwrite

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `09-file-io/file_operations.c` |
| **Type** | C source |
| **Module** | `09-file-io` |
| **Lines** | 68 total (46 code, 9 comments) |
| **Libraries** | `stdio.h`, `stdlib.h`, `string.h` |
| **Topics** | File Io |

## What It Does

Comprehensive file I/O demonstration: opening files with `fopen()`, reading/writing text with `fprintf()`/`fscanf()`, binary I/O with `fread()`/`fwrite()`, file positioning with `fseek()`, and error handling.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (16 calls) to display output to the console
3. Uses `scanf()` (1 calls) to read user input
5. Makes decisions using conditional statements (4 branches)
7. Returns 0 to indicate successful completion

## Key Code Patterns

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // ... program logic ...
    return 0;
}
```

## Libraries Used

- **`<stdio.h>`** — Standard I/O: `printf()`, `scanf()`, `fgets()`, `FILE` operations
- **`<stdlib.h>`** — Standard library: `malloc()`, `free()`, `atoi()`, `rand()`, `exit()`
- **`<string.h>`** — String manipulation: `strlen()`, `strcpy()`, `strcmp()`, `strcat()`

## Compilation

```bash
cd 09-file-io

# Compile with GCC (debug build)
gcc file_operations.c -o file_operations -std=c11 -Wall -Wextra -g

# Run
./file_operations

# Compile with Clang
clang file_operations.c -o file_operations -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc file_operations.c -o file_operations -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`
- **Library header:** `<stdlib.h>`
- **Library header:** `<string.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
