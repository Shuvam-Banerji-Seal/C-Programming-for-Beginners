# `heap_priority_queue.c`

> heap_priority_queue.c
Min/Max heap and priority queue implementation
Topics: Heapify, insertion, extraction, heap sort

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `12-advanced-data-structures/heap_priority_queue.c` |
| **Type** | C source |
| **Module** | `12-advanced-data-structures` |
| **Lines** | 307 total (219 code, 34 comments) |
| **Libraries** | `stdio.h`, `stdlib.h`, `stdbool.h` |
| **Topics** | Heap, Typedef |

## What It Does

Binary heap implementation for priority queues. Covers heapify, push, pop, and heap sort. Used in scheduling, Dijkstra's algorithm, and event-driven simulations.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (51 calls) to display output to the console
4. Allocates memory dynamically on the heap
5. Makes decisions using conditional statements (12 branches)
7. Returns 0 to indicate successful completion

## Key Code Patterns

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    // ... program logic ...
    return 0;
}
```

## Libraries Used

- **`<stdio.h>`** — Standard I/O: `printf()`, `scanf()`, `fgets()`, `FILE` operations
- **`<stdlib.h>`** — Standard library: `malloc()`, `free()`, `atoi()`, `rand()`, `exit()`
- **`<stdbool.h>`** — Boolean type: `bool`, `true`, `false` (C99+)

## Functions

| Function | Returns | Parameters | Purpose |
|----------|---------|------------|---------|
| `swap()` | `void` | `int *a, int *b` | See implementation for details |
| `parent()` | `int` | `int i` | See implementation for details |
| `leftChild()` | `int` | `int i` | See implementation for details |
| `rightChild()` | `int` | `int i` | See implementation for details |
| `shouldSwap()` | `bool` | `Heap *heap, int parent_val, int child_val` | See implementation for details |
| `heapifyUp()` | `void` | `Heap *heap, int index` | See implementation for details |
| `heapifyDown()` | `void` | `Heap *heap, int index` | See implementation for details |
| `insert()` | `bool` | `Heap *heap, int value` | See implementation for details |
| `extract()` | `int` | `Heap *heap` | See implementation for details |
| `peek()` | `int` | `Heap *heap` | See implementation for details |
| `buildHeap()` | `void` | `Heap *heap, int arr[], int n` | See implementation for details |
| `heapSort()` | `void` | `int arr[], int n` | See implementation for details |
| `printHeap()` | `void` | `Heap *heap` | See implementation for details |
| `printHeapTree()` | `void` | `Heap *heap` | See implementation for details |
| `freeHeap()` | `void` | `Heap *heap` | See implementation for details |

## Compilation

```bash
cd 12-advanced-data-structures

# Compile with GCC (debug build)
gcc heap_priority_queue.c -o heap_priority_queue -std=c11 -Wall -Wextra -g

# Run
./heap_priority_queue

# Compile with Clang
clang heap_priority_queue.c -o heap_priority_queue -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc heap_priority_queue.c -o heap_priority_queue -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`
- **Library header:** `<stdlib.h>`
- **Library header:** `<stdbool.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
