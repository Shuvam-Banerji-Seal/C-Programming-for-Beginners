# `hash_table.c`

> hash_table.c
Hash table implementation with chaining
Topics: Hash functions, collision resolution, load factor

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `11-data-structures/hash_table.c` |
| **Type** | C source |
| **Module** | `11-data-structures` |
| **Lines** | 276 total (201 code, 26 comments) |
| **Libraries** | `stdio.h`, `stdlib.h`, `string.h` |
| **Topics** | Hash Table, Typedef |

## What It Does

Implements a hash table with key-value storage, collision resolution (chaining), and dynamic resizing. A fundamental data structure used in databases, caches, and compilers.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (30 calls) to display output to the console
4. Allocates memory dynamically on the heap
5. Makes decisions using conditional statements (16 branches)
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
| `hash()` | `unsigned int` | `const char *str, int table_size` | See implementation for details |
| `insert()` | `void` | `HashTable *table, const char *key, int value` | See implementation for details |
| `search()` | `int` | `HashTable *table, const char *key, int *value` | See implementation for details |
| `delete()` | `int` | `HashTable *table, const char *key` | See implementation for details |
| `display()` | `void` | `HashTable *table` | See implementation for details |
| `loadFactor()` | `float` | `HashTable *table` | See implementation for details |
| `countCollisions()` | `int` | `HashTable *table` | See implementation for details |
| `freeHashTable()` | `void` | `HashTable *table` | See implementation for details |

## Constants & Macros

| Name | Value |
|------|-------|
| `_POSIX_C_SOURCE` | Defined in source |
| `TABLE_SIZE` | Defined in source |

## Compilation

```bash
cd 11-data-structures

# Compile with GCC (debug build)
gcc hash_table.c -o hash_table -std=c11 -Wall -Wextra -g

# Run
./hash_table

# Compile with Clang
clang hash_table.c -o hash_table -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc hash_table.c -o hash_table -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`
- **Library header:** `<stdlib.h>`
- **Library header:** `<string.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
