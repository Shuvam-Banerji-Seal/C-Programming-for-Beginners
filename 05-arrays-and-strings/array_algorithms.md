# array_algorithms.c

> Linear search

## Overview

- **File:** `05-arrays-and-strings/array_algorithms.c`
- **Language:** C source
- **Module:** `05-arrays-and-strings`
- **Lines:** 127
- **Libraries:** `stdio.h`

## Concepts

- Standard I/O: `printf`, `scanf` for console input/output
- Memory layout analysis using `sizeof` operator

## Functions

### `linearSearch()`

```c
int linearSearch(int arr[], int size, int target);
```

### `binarySearch()`

```c
int binarySearch(int arr[], int size, int target);
```

### `bubbleSort()`

```c
void bubbleSort(int arr[], int size);
```

### `selectionSort()`

```c
void selectionSort(int arr[], int size);
```

### `printArray()`

```c
void printArray(int arr[], int size);
```

### `findMax()`

```c
int findMax(int arr[], int size);
```

### `reverseArray()`

```c
void reverseArray(int arr[], int size);
```

## Compilation

```bash
cd 05-arrays-and-strings
gcc array_algorithms.c -o array_algorithms -std=c11 -Wall -Wextra
./array_algorithms
```
