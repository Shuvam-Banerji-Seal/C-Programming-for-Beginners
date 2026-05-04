# bitfields_and_unions.c

> bitfields_and_unions.c
Advanced bit fields and unions
Topics: Bit manipulation with structures, union memory sharing, packed structures

## Overview

- **File:** `08-structures-unions/bitfields_and_unions.c`
- **Language:** C source
- **Module:** `08-structures-unions`
- **Lines:** 248
- **Libraries:** `stdio.h`, `string.h`, `stdint.h`

## Concepts

- Standard I/O: `printf`, `scanf` for console input/output
- String manipulation: `strlen`, `strcpy`, `strcmp`, `strcat`
- Pointer operations: declaration, dereferencing (`*`), address-of (`&`), arithmetic
- Structures: defining structs, member access (`.`/`->`), nested structs
- Unions: shared memory layout, type punning between members
- Type aliasing with `typedef` for cleaner type definitions
- Memory layout analysis using `sizeof` operator

## Functions

### `printPermissions()`

```c
void printPermissions(Permissions p);
```

## Compilation

```bash
cd 08-structures-unions
gcc bitfields_and_unions.c -o bitfields_and_unions -std=c11 -Wall -Wextra
./bitfields_and_unions
```
