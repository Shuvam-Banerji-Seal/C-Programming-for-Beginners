# test_math.c

## Overview

- **File:** `20-professional-dev/example_project/tests/test_math.c`
- **Language:** C source
- **Module:** `tests`
- **Lines:** 34
- **Libraries:** `stdio.h`, `assert.h`, `math_utils.h`

## Concepts

- Standard I/O: `printf`, `scanf` for console input/output
- Runtime assertions for debugging program invariants

## Functions

### `test_add()`

```c
void test_add();
```

### `test_multiply()`

```c
void test_multiply();
```

### `test_factorial()`

```c
void test_factorial();
```

## Compilation

```bash
cd 20-professional-dev/example_project/tests
gcc test_math.c -o test_math -std=c11 -Wall -Wextra
./test_math
```
