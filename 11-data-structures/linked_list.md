# linked_list.c

> linked_list.c
Implements a singly linked list
Topics: Nodes, insertion, deletion, traversal

## Overview

- **File:** `11-data-structures/linked_list.c`
- **Language:** C source
- **Module:** `11-data-structures`
- **Lines:** 76
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

### `insert_front()`

```c
void insert_front(Node **head, int data);
```

### `print_list()`

```c
void print_list(Node *head);
```

### `free_list()`

```c
void free_list(Node *head);
```

## Compilation

```bash
cd 11-data-structures
gcc linked_list.c -o linked_list -std=c11 -Wall -Wextra
./linked_list
```
