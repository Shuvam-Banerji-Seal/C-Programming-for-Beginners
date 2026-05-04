# function_pointers.c

> Arithmetic operations

## Overview

- **File:** `04-functions/function_pointers.c`
- **Language:** C source
- **Module:** `04-functions`
- **Lines:** 94
- **Libraries:** `stdio.h`

## Concepts

- Standard I/O: `printf`, `scanf` for console input/output
- Pointer operations: declaration, dereferencing (`*`), address-of (`&`), arithmetic
- Type aliasing with `typedef` for cleaner type definitions
- Memory layout analysis using `sizeof` operator

## Functions

### `add()`

```c
int add(int a, int b);
```

### `subtract()`

```c
int subtract(int a, int b);
```

### `multiply()`

```c
int multiply(int a, int b);
```

### `divide()`

```c
int divide(int a, int b);
```

### `forEach()`

```c
void forEach(int arr[], int size, PrintCallback callback);
```

### `printDouble()`

```c
void printDouble(int n);
```

### `printSquare()`

```c
void printSquare(int n);
```

### `printCube()`

```c
void printCube(int n);
```

## Compilation

```bash
cd 04-functions
gcc function_pointers.c -o function_pointers -std=c11 -Wall -Wextra
./function_pointers
```
