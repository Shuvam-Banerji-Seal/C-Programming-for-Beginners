# basic_functions.c

> Function declarations

## Overview

- **File:** `04-functions/basic_functions.c`
- **Language:** C source
- **Module:** `04-functions`
- **Lines:** 63
- **Libraries:** `stdio.h`

## Concepts

- Standard I/O: `printf`, `scanf` for console input/output

## Functions

### `greet()`

```c
void greet(void);
```

### `add()`

```c
int add(int a, int b);
```

### `subtract()`

```c
int subtract(int a, int b);
```

### `divide()`

```c
float divide(float a, float b);
```

### `maximum()`

```c
int maximum(int a, int b, int c);
```

### `printLine()`

```c
void printLine(int length);
```

## Compilation

```bash
cd 04-functions
gcc basic_functions.c -o basic_functions -std=c11 -Wall -Wextra
./basic_functions
```
