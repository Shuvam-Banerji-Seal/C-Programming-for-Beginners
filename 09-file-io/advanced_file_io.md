# `advanced_file_io.c`

> advanced_file_io.c
Advanced file I/O operations
Topics: CSV parsing, structured data I/O, file positioning, error handling

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `09-file-io/advanced_file_io.c` |
| **Type** | C source |
| **Module** | `09-file-io` |
| **Lines** | 288 total (197 code, 34 comments) |
| **Libraries** | `stdio.h`, `stdlib.h`, `string.h` |
| **Topics** | Typedef |

## What It Does

Advanced file operations: memory-mapped I/O with `mmap()`, directory traversal with `opendir()`/`readdir()`, file locking, and asynchronous I/O patterns.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (33 calls) to display output to the console
3. Uses `scanf()` (1 calls) to read user input
5. Makes decisions using conditional statements (12 branches)
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

## Functions

| Function | Returns | Parameters | Purpose |
|----------|---------|------------|---------|
| `writeCSV()` | `void` | `const char *filename, Student students[], int coun...` | See implementation for details |
| `readCSV()` | `int` | `const char *filename, Student students[], int max_...` | See implementation for details |
| `writeBinaryRecords()` | `void` | `const char *filename, Student students[], int coun...` | See implementation for details |
| `readBinaryRecords()` | `int` | `const char *filename, Student students[], int max_...` | See implementation for details |
| `demonstrateFilePositioning()` | `void` | `const char *filename` | See implementation for details |
| `appendToCSV()` | `void` | `const char *filename, Student *student` | See implementation for details |
| `countLines()` | `int` | `const char *filename` | See implementation for details |
| `copyFile()` | `void` | `const char *source, const char *dest` | See implementation for details |

## Compilation

```bash
cd 09-file-io

# Compile with GCC (debug build)
gcc advanced_file_io.c -o advanced_file_io -std=c11 -Wall -Wextra -g

# Run
./advanced_file_io

# Compile with Clang
clang advanced_file_io.c -o advanced_file_io -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc advanced_file_io.c -o advanced_file_io -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`
- **Library header:** `<stdlib.h>`
- **Library header:** `<string.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
