# `math_utils.h`

> *
@brief Add two integers
@param a First number
@param b Second number
@return Sum of a and b

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `20-professional-dev/example_project/include/math_utils.h` |
| **Type** | C header |
| **Module** | `include` |
| **Lines** | 28 total (6 code, 17 comments) |
| **Topics** | Math Utilities |

## What It Does

Mathematical utility functions: basic operations, statistical calculations, or numerical methods. Part of the professional development module showing modular code organization with headers and implementation files.

## Key Code Patterns

```c

int main(void) {
    // ... program logic ...
    return 0;
}
```

## Constants & Macros

| Name | Value |
|------|-------|
| `MATH_UTILS_H` | Defined in source |

## Compilation

```bash
cd 20-professional-dev/example_project/include

# Compile with GCC (debug build)
gcc math_utils.h -o math_utils -std=c11 -Wall -Wextra -g

# Run
./math_utils

# Compile with Clang
clang math_utils.h -o math_utils -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc math_utils.h -o math_utils -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Buggy version:** [`math_utils.h`](math_utils.h) (learn from common mistakes)

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
