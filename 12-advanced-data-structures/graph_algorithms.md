# `graph_algorithms.c`

> graph_algorithms.c
Graph algorithms implementation
Topics: DFS, BFS, shortest path, connected components

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `12-advanced-data-structures/graph_algorithms.c` |
| **Type** | C source |
| **Module** | `12-advanced-data-structures` |
| **Lines** | 349 total (255 code, 28 comments) |
| **Libraries** | `stdio.h`, `stdlib.h`, `limits.h`, `stdbool.h` |
| **Topics** | Graph, Typedef |

## What It Does

Graph algorithms including BFS, DFS, adjacency list/matrix representations, and shortest path. Foundation for network routing, social networks, and pathfinding.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (31 calls) to display output to the console
4. Allocates memory dynamically on the heap
5. Makes decisions using conditional statements (12 branches)
7. Returns 0 to indicate successful completion

## Key Code Patterns

```c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int main(void) {
    // ... program logic ...
    return 0;
}
```

## Libraries Used

- **`<stdio.h>`** — Standard I/O: `printf()`, `scanf()`, `fgets()`, `FILE` operations
- **`<stdlib.h>`** — Standard library: `malloc()`, `free()`, `atoi()`, `rand()`, `exit()`
- **`<limits.h>`** — Integer limits: `INT_MAX`, `LONG_MIN`, `CHAR_BIT`
- **`<stdbool.h>`** — Boolean type: `bool`, `true`, `false` (C99+)

## Functions

| Function | Returns | Parameters | Purpose |
|----------|---------|------------|---------|
| `initQueue()` | `void` | `Queue *q` | See implementation for details |
| `isEmpty()` | `bool` | `Queue *q` | See implementation for details |
| `enqueue()` | `void` | `Queue *q, int value` | See implementation for details |
| `dequeue()` | `int` | `Queue *q` | See implementation for details |
| `addEdge()` | `void` | `Graph *graph, int src, int dest, int weight` | See implementation for details |
| `DFSUtil()` | `void` | `Graph *graph, int vertex, bool visited[]` | See implementation for details |
| `DFS()` | `void` | `Graph *graph, int start` | See implementation for details |
| `BFS()` | `void` | `Graph *graph, int start` | See implementation for details |
| `shortestPath()` | `void` | `Graph *graph, int start, int end` | See implementation for details |
| `countComponents()` | `int` | `Graph *graph` | See implementation for details |
| `hasCycleUtil()` | `bool` | `Graph *graph, int vertex, bool visited[], int pare...` | See implementation for details |
| `hasCycle()` | `bool` | `Graph *graph` | See implementation for details |
| `printGraph()` | `void` | `Graph *graph` | See implementation for details |
| `freeGraph()` | `void` | `Graph *graph` | See implementation for details |

## Constants & Macros

| Name | Value |
|------|-------|
| `MAX_VERTICES` | Defined in source |

## Compilation

```bash
cd 12-advanced-data-structures

# Compile with GCC (debug build)
gcc graph_algorithms.c -o graph_algorithms -std=c11 -Wall -Wextra -g

# Run
./graph_algorithms

# Compile with Clang
clang graph_algorithms.c -o graph_algorithms -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc graph_algorithms.c -o graph_algorithms -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`
- **Library header:** `<stdlib.h>`
- **Library header:** `<limits.h>`
- **Library header:** `<stdbool.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
