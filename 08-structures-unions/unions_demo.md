# unions_demo.c

> unions_demo.c
Demonstrates unions in C
Topics: union definition, memory sharing, use cases

## Overview

- **File:** `08-structures-unions/unions_demo.c`
- **Language:** C source
- **Module:** `08-structures-unions`
- **Lines:** 51
- **Libraries:** `stdio.h`, `string.h`

## Concepts

- Standard I/O: `printf`, `scanf` for console input/output
- String manipulation: `strlen`, `strcpy`, `strcmp`, `strcat`
- Pointer operations: declaration, dereferencing (`*`), address-of (`&`), arithmetic
- Unions: shared memory layout, type punning between members
- Type aliasing with `typedef` for cleaner type definitions
- Memory layout analysis using `sizeof` operator

## Compilation

```bash
cd 08-structures-unions
gcc unions_demo.c -o unions_demo -std=c11 -Wall -Wextra
./unions_demo
```
