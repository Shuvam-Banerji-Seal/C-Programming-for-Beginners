# `scope_lifetime.c`

> Global variable

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `04-functions/scope_lifetime.c` |
| **Type** | C source |
| **Module** | `04-functions` |
| **Lines** | 99 total (66 code, 14 comments) |
| **Libraries** | `stdio.h` |
| **Topics** | Scope Lifetime |

## What It Does

Demonstrates variable scope (global, local, block) and lifetime (static, automatic, allocated) in C. Explains the difference between where a variable is accessible and how long it exists in memory.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (26 calls) to display output to the console
7. Returns 0 to indicate successful completion

## Key Code Patterns

```c
#include <stdio.h>

int main(void) {
    // ... program logic ...
    return 0;
}
```

## Libraries Used

- **`<stdio.h>`** — Standard I/O: `printf()`, `scanf()`, `fgets()`, `FILE` operations

## Functions

| Function | Returns | Parameters | Purpose |
|----------|---------|------------|---------|
| `counter()` | `void` | `` | See implementation for details |
| `localDemo()` | `void` | `` | See implementation for details |
| `modifyGlobal()` | `void` | `` | See implementation for details |
| `shadowDemo()` | `void` | `` | See implementation for details |
| `registerDemo()` | `void` | `` | See implementation for details |
| `blockScope()` | `void` | `` | See implementation for details |

## Compilation

```bash
cd 04-functions

# Compile with GCC (debug build)
gcc scope_lifetime.c -o scope_lifetime -std=c11 -Wall -Wextra -g

# Run
./scope_lifetime

# Compile with Clang
clang scope_lifetime.c -o scope_lifetime -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc scope_lifetime.c -o scope_lifetime -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
