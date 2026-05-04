# bst.c

> Create new node

## Overview

- **File:** `12-advanced-data-structures/bst.c`
- **Language:** C source
- **Module:** `12-advanced-data-structures`
- **Lines:** 186
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

### `inorder()`

```c
void inorder(Node *root);
```

### `preorder()`

```c
void preorder(Node *root);
```

### `postorder()`

```c
void postorder(Node *root);
```

### `countNodes()`

```c
int countNodes(Node *root);
```

### `height()`

```c
int height(Node *root);
```

## Compilation

```bash
cd 12-advanced-data-structures
gcc bst.c -o bst -std=c11 -Wall -Wextra
./bst
```
