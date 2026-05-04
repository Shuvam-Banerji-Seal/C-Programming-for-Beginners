# doubly_linked_list.c

> doubly_linked_list.c
Doubly linked list implementation
Topics: Insertion, deletion, traversal in both directions

## Overview

- **File:** `11-data-structures/doubly_linked_list.c`
- **Language:** C source
- **Module:** `11-data-structures`
- **Lines:** 301
- **Libraries:** `stdio.h`, `stdlib.h`

## Concepts

- Standard I/O: `printf`, `scanf` for console input/output
- Standard library: memory allocation (`malloc`/`free`), conversions (`atoi`), exit codes
- Pointer operations: declaration, dereferencing (`*`), address-of (`&`), arithmetic
- Structures: defining structs, member access (`.`/`->`), nested structs
- Heap memory allocation: `malloc`/`calloc`/`realloc` and `free`
- Type aliasing with `typedef` for cleaner type definitions
- Memory layout analysis using `sizeof` operator

## Functions

### `initList()`

```c
void initList(DoublyLinkedList *list);
```

### `insertFront()`

```c
void insertFront(DoublyLinkedList *list, int data);
```

### `insertEnd()`

```c
void insertEnd(DoublyLinkedList *list, int data);
```

### `insertAt()`

```c
int insertAt(DoublyLinkedList *list, int data, int position);
```

### `deleteFront()`

```c
int deleteFront(DoublyLinkedList *list);
```

### `deleteEnd()`

```c
int deleteEnd(DoublyLinkedList *list);
```

### `deleteValue()`

```c
int deleteValue(DoublyLinkedList *list, int value);
```

### `printForward()`

```c
void printForward(DoublyLinkedList *list);
```

### `printBackward()`

```c
void printBackward(DoublyLinkedList *list);
```

### `reverseList()`

```c
void reverseList(DoublyLinkedList *list);
```

### `freeList()`

```c
void freeList(DoublyLinkedList *list);
```

## Compilation

```bash
cd 11-data-structures
gcc doubly_linked_list.c -o doubly_linked_list -std=c11 -Wall -Wextra
./doubly_linked_list
```
