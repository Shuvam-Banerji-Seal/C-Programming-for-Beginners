# stack.c

> stack.c
Implements a stack data structure
Topics: LIFO, push, pop, peek

## Overview

- **File:** `11-data-structures/stack.c`
- **Language:** C source
- **Module:** `11-data-structures`
- **Lines:** 64
- **Libraries:** `stdio.h`, `stdlib.h`

## Concepts

- Standard I/O: `printf`, `scanf` for console input/output
- Standard library: memory allocation (`malloc`/`free`), conversions (`atoi`), exit codes
- Pointer operations: declaration, dereferencing (`*`), address-of (`&`), arithmetic
- Structures: defining structs, member access (`.`/`->`), nested structs
- Type aliasing with `typedef` for cleaner type definitions

## Functions

### `init_stack()`

```c
void init_stack(Stack *s);
```

### `is_empty()`

```c
int is_empty(Stack *s);
```

### `is_full()`

```c
int is_full(Stack *s);
```

### `push()`

```c
void push(Stack *s, int value);
```

### `pop()`

```c
int pop(Stack *s);
```

## Compilation

```bash
cd 11-data-structures
gcc stack.c -o stack -std=c11 -Wall -Wextra
./stack
```
