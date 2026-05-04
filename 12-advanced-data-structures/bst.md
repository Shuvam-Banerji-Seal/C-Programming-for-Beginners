# `bst.c`

> Create new node

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `12-advanced-data-structures/bst.c` |
| **Type** | C source |
| **Module** | `12-advanced-data-structures` |
| **Lines** | 186 total (136 code, 17 comments) |
| **Libraries** | `stdio.h`, `stdlib.h` |
| **Topics** | Binary Search Tree, Typedef |

## What It Does

Binary Search Tree implementation with insert, search, delete, and traversal (in-order, pre-order, post-order). Demonstrates recursive tree algorithms and pointer manipulation.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (24 calls) to display output to the console
4. Allocates memory dynamically on the heap
5. Makes decisions using conditional statements (12 branches)
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
| `inorder()` | `void` | `Node *root` | See implementation for details |
| `preorder()` | `void` | `Node *root` | See implementation for details |
| `postorder()` | `void` | `Node *root` | See implementation for details |
| `countNodes()` | `int` | `Node *root` | See implementation for details |
| `height()` | `int` | `Node *root` | See implementation for details |

## Compilation

```bash
cd 12-advanced-data-structures

# Compile with GCC (debug build)
gcc bst.c -o bst -std=c11 -Wall -Wextra -g

# Run
./bst

# Compile with Clang
clang bst.c -o bst -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc bst.c -o bst -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`
- **Library header:** `<stdlib.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
