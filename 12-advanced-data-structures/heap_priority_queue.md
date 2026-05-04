# heap_priority_queue.c

> heap_priority_queue.c
Min/Max heap and priority queue implementation
Topics: Heapify, insertion, extraction, heap sort

## Overview

- **File:** `12-advanced-data-structures/heap_priority_queue.c`
- **Language:** C source
- **Module:** `12-advanced-data-structures`
- **Lines:** 307
- **Libraries:** `stdio.h`, `stdlib.h`, `stdbool.h`

## Concepts

- Standard I/O: `printf`, `scanf` for console input/output
- Standard library: memory allocation (`malloc`/`free`), conversions (`atoi`), exit codes
- Pointer operations: declaration, dereferencing (`*`), address-of (`&`), arithmetic
- Structures: defining structs, member access (`.`/`->`), nested structs
- Heap memory allocation: `malloc`/`calloc`/`realloc` and `free`
- Type aliasing with `typedef` for cleaner type definitions
- Memory layout analysis using `sizeof` operator

## Functions

### `swap()`

```c
void swap(int *a, int *b);
```

### `parent()`

```c
int parent(int i);
```

### `leftChild()`

```c
int leftChild(int i);
```

### `rightChild()`

```c
int rightChild(int i);
```

### `shouldSwap()`

```c
bool shouldSwap(Heap *heap, int parent_val, int child_val);
```

### `heapifyUp()`

```c
void heapifyUp(Heap *heap, int index);
```

### `heapifyDown()`

```c
void heapifyDown(Heap *heap, int index);
```

### `insert()`

```c
bool insert(Heap *heap, int value);
```

### `extract()`

```c
int extract(Heap *heap);
```

### `peek()`

```c
int peek(Heap *heap);
```

### `buildHeap()`

```c
void buildHeap(Heap *heap, int arr[], int n);
```

### `heapSort()`

```c
void heapSort(int arr[], int n);
```

### `printHeap()`

```c
void printHeap(Heap *heap);
```

### `printHeapTree()`

```c
void printHeapTree(Heap *heap);
```

### `freeHeap()`

```c
void freeHeap(Heap *heap);
```

## Compilation

```bash
cd 12-advanced-data-structures
gcc heap_priority_queue.c -o heap_priority_queue -std=c11 -Wall -Wextra
./heap_priority_queue
```
