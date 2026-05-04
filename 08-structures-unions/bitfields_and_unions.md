# `bitfields_and_unions.c`

> bitfields_and_unions.c
Advanced bit fields and unions
Topics: Bit manipulation with structures, union memory sharing, packed structures

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `08-structures-unions/bitfields_and_unions.c` |
| **Type** | C source |
| **Module** | `08-structures-unions` |
| **Lines** | 248 total (191 code, 23 comments) |
| **Libraries** | `stdio.h`, `string.h`, `stdint.h` |
| **Topics** | Bit Fields, Typedef |

## What It Does

Bit fields allow packing multiple variables into a single integer type, saving memory. Unions let different data types share the same memory location. Essential for embedded systems, protocol parsing, and low-level programming.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (45 calls) to display output to the console
5. Makes decisions using conditional statements (1 branches)
7. Returns 0 to indicate successful completion

## Key Code Patterns

```c
#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main(void) {
    // ... program logic ...
    return 0;
}
```

## Libraries Used

- **`<stdio.h>`** — Standard I/O: `printf()`, `scanf()`, `fgets()`, `FILE` operations
- **`<string.h>`** — String manipulation: `strlen()`, `strcpy()`, `strcmp()`, `strcat()`
- **`<stdint.h>`** — Fixed-width integers: `int32_t`, `uint64_t`, `intptr_t`

## Functions

| Function | Returns | Parameters | Purpose |
|----------|---------|------------|---------|
| `printPermissions()` | `void` | `Permissions p` | See implementation for details |

## Compilation

```bash
cd 08-structures-unions

# Compile with GCC (debug build)
gcc bitfields_and_unions.c -o bitfields_and_unions -std=c11 -Wall -Wextra -g

# Run
./bitfields_and_unions

# Compile with Clang
clang bitfields_and_unions.c -o bitfields_and_unions -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc bitfields_and_unions.c -o bitfields_and_unions -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`
- **Library header:** `<string.h>`
- **Library header:** `<stdint.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
