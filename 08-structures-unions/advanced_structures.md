# `advanced_structures.c`

> advanced_structures.c
Advanced structure operations
Topics: Nested structures, bit fields, enums, pointers to structures, self-referential structures

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `08-structures-unions/advanced_structures.c` |
| **Type** | C source |
| **Module** | `08-structures-unions` |
| **Lines** | 259 total (195 code, 28 comments) |
| **Libraries** | `stdio.h`, `string.h`, `stdlib.h` |
| **Topics** | Typedef, Enum |

## What It Does

Advanced structure patterns: flexible array members, self-referential structures, function pointers in structs (simulating methods), and opaque types for encapsulation.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (42 calls) to display output to the console
4. Allocates memory dynamically on the heap
5. Makes decisions using conditional statements (3 branches)
7. Returns 0 to indicate successful completion

## Key Code Patterns

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    // ... program logic ...
    return 0;
}
```

## Libraries Used

- **`<stdio.h>`** — Standard I/O: `printf()`, `scanf()`, `fgets()`, `FILE` operations
- **`<string.h>`** — String manipulation: `strlen()`, `strcpy()`, `strcmp()`, `strcat()`
- **`<stdlib.h>`** — Standard library: `malloc()`, `free()`, `atoi()`, `rand()`, `exit()`

## Functions

| Function | Returns | Parameters | Purpose |
|----------|---------|------------|---------|
| `printDate()` | `void` | `Date d` | See implementation for details |
| `printAddress()` | `void` | `Address addr` | See implementation for details |
| `updateSalary()` | `void` | `Employee *emp, float percentage` | See implementation for details |
| `inorder()` | `void` | `TreeNode *root` | See implementation for details |

## Compilation

```bash
cd 08-structures-unions

# Compile with GCC (debug build)
gcc advanced_structures.c -o advanced_structures -std=c11 -Wall -Wextra -g

# Run
./advanced_structures

# Compile with Clang
clang advanced_structures.c -o advanced_structures -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc advanced_structures.c -o advanced_structures -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`
- **Library header:** `<string.h>`
- **Library header:** `<stdlib.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
