# `linked_list.c`

> linked_list.c
Implements a singly linked list
Topics: Nodes, insertion, deletion, traversal

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `11-data-structures/linked_list.c` |
| **Type** | C source |
| **Module** | `11-data-structures` |
| **Lines** | 76 total (50 code, 11 comments) |
| **Libraries** | `stdio.h`, `stdlib.h` |
| **Topics** | Linked List, Typedef |

## What It Does

Implements a singly linked list with insertion, deletion, traversal, and search operations. Covers dynamic node allocation, pointer manipulation, and the `->` operator for struct-pointer access.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (9 calls) to display output to the console
4. Allocates memory dynamically on the heap
5. Makes decisions using conditional statements (2 branches)
7. Returns 0 to indicate successful completion

## Key Code Patterns

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // ... program logic ...
    return 0;
}
```

## Libraries Used

- **`<stdio.h>`** — Standard I/O: `printf()`, `scanf()`, `fgets()`, `FILE` operations
- **`<stdlib.h>`** — Standard library: `malloc()`, `free()`, `atoi()`, `rand()`, `exit()`

## Functions

| Function | Returns | Parameters | Purpose |
|----------|---------|------------|---------|
| `insert_front()` | `void` | `Node **head, int data` | See implementation for details |
| `print_list()` | `void` | `Node *head` | See implementation for details |
| `free_list()` | `void` | `Node *head` | See implementation for details |

## Compilation

```bash
cd 11-data-structures

# Compile with GCC (debug build)
gcc linked_list.c -o linked_list -std=c11 -Wall -Wextra -g

# Run
./linked_list

# Compile with Clang
clang linked_list.c -o linked_list -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc linked_list.c -o linked_list -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`
- **Library header:** `<stdlib.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
