# `dynamic_memory.c`

> dynamic_memory.c
Demonstrates dynamic memory allocation in C
Topics: malloc, calloc, realloc, free, memory leaks

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `07-memory-management/dynamic_memory.c` |
| **Type** | C source |
| **Module** | `07-memory-management` |
| **Lines** | 139 total (103 code, 16 comments) |
| **Libraries** | `stdio.h`, `stdlib.h`, `string.h` |
| **Topics** | Dynamic Memory |

## What It Does

Covers heap memory management with `malloc()`, `calloc()`, `realloc()`, and `free()`. Demonstrates proper allocation patterns, NULL-checking, and avoiding memory leaks. Essential for writing production C code.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (38 calls) to display output to the console
4. Allocates memory dynamically on the heap
5. Makes decisions using conditional statements (7 branches)
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
cd 07-memory-management

# Compile with GCC (debug build)
gcc dynamic_memory.c -o dynamic_memory -std=c11 -Wall -Wextra -g

# Run
./dynamic_memory

# Compile with Clang
clang dynamic_memory.c -o dynamic_memory -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc dynamic_memory.c -o dynamic_memory -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`
- **Library header:** `<stdlib.h>`
- **Library header:** `<string.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
