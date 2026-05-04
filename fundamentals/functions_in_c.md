# functions_in_c.c

> functions declaration

## Overview

- **File:** `fundamentals/functions_in_c.c`
- **Language:** C source
- **Module:** `fundamentals`
- **Lines:** 58
- **Libraries:** `stdio.h`

## Concepts

- Standard I/O: `printf`, `scanf` for console input/output
- Pointer operations: declaration, dereferencing (`*`), address-of (`&`), arithmetic

## Functions

### `function1()`

```c
void function1();
```

### `function2()`

```c
void function2(int a);
```

### `function3()`

```c
char function3();
```

### `function4()`

```c
int function4(int a, int b);
```

### `function5()`

```c
float function5(float a, float b);
```

### `function6()`

```c
int function6(float a, float b);
```

## Compilation

```bash
cd fundamentals
gcc functions_in_c.c -o functions_in_c -std=c11 -Wall -Wextra
./functions_in_c
```
