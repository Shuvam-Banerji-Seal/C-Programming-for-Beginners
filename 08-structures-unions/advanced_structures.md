# advanced_structures.c

> advanced_structures.c
Advanced structure operations
Topics: Nested structures, bit fields, enums, pointers to structures, self-referential structures

## Overview

- **File:** `08-structures-unions/advanced_structures.c`
- **Language:** C source
- **Module:** `08-structures-unions`
- **Lines:** 259
- **Libraries:** `stdio.h`, `string.h`, `stdlib.h`

## Concepts

- Standard I/O: `printf`, `scanf` for console input/output
- Standard library: memory allocation (`malloc`/`free`), conversions (`atoi`), exit codes
- String manipulation: `strlen`, `strcpy`, `strcmp`, `strcat`
- Pointer operations: declaration, dereferencing (`*`), address-of (`&`), arithmetic
- Structures: defining structs, member access (`.`/`->`), nested structs
- Heap memory allocation: `malloc`/`calloc`/`realloc` and `free`
- Type aliasing with `typedef` for cleaner type definitions
- Enumerations (`enum`) for named integer constants
- Memory layout analysis using `sizeof` operator

## Functions

### `printDate()`

```c
void printDate(Date d);
```

### `printAddress()`

```c
void printAddress(Address addr);
```

### `updateSalary()`

```c
void updateSalary(Employee *emp, float percentage);
```

### `inorder()`

```c
void inorder(TreeNode *root);
```

## Compilation

```bash
cd 08-structures-unions
gcc advanced_structures.c -o advanced_structures -std=c11 -Wall -Wextra
./advanced_structures
```
