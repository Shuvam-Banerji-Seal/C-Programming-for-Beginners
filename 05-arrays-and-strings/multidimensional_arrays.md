# multidimensional_arrays.c

> multidimensional_arrays.c
Advanced multi-dimensional array operations
Topics: 2D arrays, 3D arrays, matrix operations, dynamic allocation

## Overview

- **File:** `05-arrays-and-strings/multidimensional_arrays.c`
- **Language:** C source
- **Module:** `05-arrays-and-strings`
- **Lines:** 220
- **Libraries:** `stdio.h`, `stdlib.h`

## Concepts

- Standard I/O: `printf`, `scanf` for console input/output
- Standard library: memory allocation (`malloc`/`free`), conversions (`atoi`), exit codes
- Pointer operations: declaration, dereferencing (`*`), address-of (`&`), arithmetic

## Functions

### `matrixAdd()`

```c
void matrixAdd(int rows, int cols, int a[rows][cols], int b[rows][cols], int result[rows][cols]);
```

### `matrixMultiply()`

```c
void matrixMultiply(int r1, int c1, int a[r1][c1], int r2, int c2, int b[r2][c2], int result[r1][c2]);
```

### `matrixTranspose()`

```c
void matrixTranspose(int rows, int cols, int matrix[rows][cols], int result[cols][rows]);
```

### `printMatrix()`

```c
void printMatrix(int rows, int cols, int matrix[rows][cols]);
```

### `spiralTraversal()`

```c
void spiralTraversal(int rows, int cols, int matrix[rows][cols]);
```

### `searchMatrix()`

```c
int searchMatrix(int rows, int cols, int matrix[rows][cols], int target);
```

### `demonstrate3DArray()`

```c
void demonstrate3DArray();
```

## Compilation

```bash
cd 05-arrays-and-strings
gcc multidimensional_arrays.c -o multidimensional_arrays -std=c11 -Wall -Wextra
./multidimensional_arrays
```
