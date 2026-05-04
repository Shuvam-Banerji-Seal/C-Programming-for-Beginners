# `doubly_linked_list.c`

> doubly_linked_list.c
Doubly linked list implementation
Topics: Insertion, deletion, traversal in both directions

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `11-data-structures/doubly_linked_list.c` |
| **Type** | C source |
| **Module** | `11-data-structures` |
| **Lines** | 301 total (227 code, 24 comments) |
| **Libraries** | `stdio.h`, `stdlib.h` |
| **Topics** | Linked List, Doubly Linked List, Typedef |

## What It Does

Extends the linked list concept with `prev` pointers for bidirectional traversal. Shows how doubly-linked lists enable O(1) deletion from both ends and reverse iteration.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (26 calls) to display output to the console
4. Allocates memory dynamically on the heap
5. Makes decisions using conditional statements (19 branches)
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
| `initList()` | `void` | `DoublyLinkedList *list` | See implementation for details |
| `insertFront()` | `void` | `DoublyLinkedList *list, int data` | See implementation for details |
| `insertEnd()` | `void` | `DoublyLinkedList *list, int data` | See implementation for details |
| `insertAt()` | `int` | `DoublyLinkedList *list, int data, int position` | See implementation for details |
| `deleteFront()` | `int` | `DoublyLinkedList *list` | See implementation for details |
| `deleteEnd()` | `int` | `DoublyLinkedList *list` | See implementation for details |
| `deleteValue()` | `int` | `DoublyLinkedList *list, int value` | See implementation for details |
| `printForward()` | `void` | `DoublyLinkedList *list` | See implementation for details |
| `printBackward()` | `void` | `DoublyLinkedList *list` | See implementation for details |
| `reverseList()` | `void` | `DoublyLinkedList *list` | See implementation for details |
| `freeList()` | `void` | `DoublyLinkedList *list` | See implementation for details |

## Compilation

```bash
cd 11-data-structures

# Compile with GCC (debug build)
gcc doubly_linked_list.c -o doubly_linked_list -std=c11 -Wall -Wextra -g

# Run
./doubly_linked_list

# Compile with Clang
clang doubly_linked_list.c -o doubly_linked_list -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc doubly_linked_list.c -o doubly_linked_list -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`
- **Library header:** `<stdlib.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
