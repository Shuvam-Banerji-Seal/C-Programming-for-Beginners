# graph_algorithms.c

> graph_algorithms.c
Graph algorithms implementation
Topics: DFS, BFS, shortest path, connected components

## Overview

- **File:** `12-advanced-data-structures/graph_algorithms.c`
- **Language:** C source
- **Module:** `12-advanced-data-structures`
- **Lines:** 349
- **Libraries:** `stdio.h`, `stdlib.h`, `limits.h`, `stdbool.h`

## Concepts

- Standard I/O: `printf`, `scanf` for console input/output
- Standard library: memory allocation (`malloc`/`free`), conversions (`atoi`), exit codes
- Pointer operations: declaration, dereferencing (`*`), address-of (`&`), arithmetic
- Structures: defining structs, member access (`.`/`->`), nested structs
- Heap memory allocation: `malloc`/`calloc`/`realloc` and `free`
- Type aliasing with `typedef` for cleaner type definitions
- Memory layout analysis using `sizeof` operator

## Functions

### `initQueue()`

```c
void initQueue(Queue *q);
```

### `isEmpty()`

```c
bool isEmpty(Queue *q);
```

### `enqueue()`

```c
void enqueue(Queue *q, int value);
```

### `dequeue()`

```c
int dequeue(Queue *q);
```

### `addEdge()`

```c
void addEdge(Graph *graph, int src, int dest, int weight);
```

### `DFSUtil()`

```c
void DFSUtil(Graph *graph, int vertex, bool visited[]);
```

### `DFS()`

```c
void DFS(Graph *graph, int start);
```

### `BFS()`

```c
void BFS(Graph *graph, int start);
```

### `shortestPath()`

```c
void shortestPath(Graph *graph, int start, int end);
```

### `countComponents()`

```c
int countComponents(Graph *graph);
```

### `hasCycleUtil()`

```c
bool hasCycleUtil(Graph *graph, int vertex, bool visited[], int parent);
```

### `hasCycle()`

```c
bool hasCycle(Graph *graph);
```

### `printGraph()`

```c
void printGraph(Graph *graph);
```

### `freeGraph()`

```c
void freeGraph(Graph *graph);
```

## Compilation

```bash
cd 12-advanced-data-structures
gcc graph_algorithms.c -o graph_algorithms -std=c11 -Wall -Wextra
./graph_algorithms
```
