# pass_by_value_reference.c

> Pass by value

## Overview

- **File:** `04-functions/pass_by_value_reference.c`
- **Language:** C source
- **Module:** `04-functions`
- **Lines:** 72
- **Libraries:** `stdio.h`

## Concepts

- Standard I/O: `printf`, `scanf` for console input/output
- Memory layout analysis using `sizeof` operator

## Functions

### `tryToModify()`

```c
void tryToModify(int x);
```

### `modify()`

```c
void modify(int *x);
```

### `swap()`

```c
void swap(int *a, int *b);
```

### `getMinMax()`

```c
void getMinMax(int arr[], int size, int *min, int *max);
```

## Compilation

```bash
cd 04-functions
gcc pass_by_value_reference.c -o pass_by_value_reference -std=c11 -Wall -Wextra
./pass_by_value_reference
```
