# `math_utils.c`

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `20-professional-dev/example_project/lib/math_utils.c` |
| **Type** | C source |
| **Module** | `lib` |
| **Lines** | 15 total (10 code, 0 comments) |
| **Libraries** | `math_utils.h` |
| **Topics** | Math Utilities |

## What It Does

Mathematical utility functions: basic operations, statistical calculations, or numerical methods. Part of the professional development module showing modular code organization with headers and implementation files.

## Key Code Patterns

```c
#include <math_utils.h>

int main(void) {
    // ... program logic ...
    return 0;
}
```

## Libraries Used

- **`<math_utils.h>`** — Standard C library

## Functions

| Function | Returns | Parameters | Purpose |
|----------|---------|------------|---------|
| `add()` | `int` | `int a, int b` | See implementation for details |
| `multiply()` | `int` | `int a, int b` | See implementation for details |
| `factorial()` | `int` | `int n` | See implementation for details |

## Compilation

```bash
cd 20-professional-dev/example_project/lib

# Compile with GCC (debug build)
gcc math_utils.c -o math_utils -std=c11 -Wall -Wextra -g

# Run
./math_utils

# Compile with Clang
clang math_utils.c -o math_utils -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc math_utils.c -o math_utils -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<math_utils.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
