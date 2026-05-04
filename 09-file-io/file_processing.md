# `file_processing.c`

> file_processing.c
File processing and text manipulation
Topics: Line-by-line processing, word counting, search and replace

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `09-file-io/file_processing.c` |
| **Type** | C source |
| **Module** | `09-file-io` |
| **Lines** | 269 total (193 code, 28 comments) |
| **Libraries** | `stdio.h`, `stdlib.h`, `string.h`, `ctype.h` |
| **Topics** | Typedef |

## What It Does

File processing patterns: reading structured data (CSV, config files), line-by-line processing, buffered I/O, and large file handling strategies.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (30 calls) to display output to the console
4. Allocates memory dynamically on the heap
5. Makes decisions using conditional statements (12 branches)
7. Returns 0 to indicate successful completion

## Key Code Patterns

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    // ... program logic ...
    return 0;
}
```

## Libraries Used

- **`<stdio.h>`** — Standard I/O: `printf()`, `scanf()`, `fgets()`, `FILE` operations
- **`<stdlib.h>`** — Standard library: `malloc()`, `free()`, `atoi()`, `rand()`, `exit()`
- **`<string.h>`** — String manipulation: `strlen()`, `strcpy()`, `strcmp()`, `strcat()`
- **`<ctype.h>`** — Character handling: `isalpha()`, `isdigit()`, `toupper()`

## Functions

| Function | Returns | Parameters | Purpose |
|----------|---------|------------|---------|
| `analyzeFile()` | `FileStats` | `const char *filename` | See implementation for details |
| `searchInFile()` | `int` | `const char *filename, const char *word` | See implementation for details |
| `replaceInFile()` | `void` | `const char *filename, const char *old_word, const ...` | See implementation for details |
| `reverseFile()` | `void` | `const char *filename, const char *output` | See implementation for details |
| `mergeFiles()` | `void` | `const char *file1, const char *file2, const char *...` | See implementation for details |

## Compilation

```bash
cd 09-file-io

# Compile with GCC (debug build)
gcc file_processing.c -o file_processing -std=c11 -Wall -Wextra -g

# Run
./file_processing

# Compile with Clang
clang file_processing.c -o file_processing -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc file_processing.c -o file_processing -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`
- **Library header:** `<stdlib.h>`
- **Library header:** `<string.h>`
- **Library header:** `<ctype.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
