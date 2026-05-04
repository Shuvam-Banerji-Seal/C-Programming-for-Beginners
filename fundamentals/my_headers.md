# `my_headers.h`

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `fundamentals/my_headers.h` |
| **Type** | C header |
| **Module** | `fundamentals` |
| **Lines** | 7 total (0 code, 0 comments) |
| **Libraries** | `stdio.h`, `stdlib.h`, `string.h`, `math.h` |
| **Topics** | Fundamentals |

## What It Does

Variable declaration, initialization, and the `auto` storage class. Covers naming conventions, basic types, and how variables map to memory.

## Key Code Patterns

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void) {
    // ... program logic ...
    return 0;
}
```

## Libraries Used

- **`<stdio.h>`** — Standard I/O: `printf()`, `scanf()`, `fgets()`, `FILE` operations
- **`<stdlib.h>`** — Standard library: `malloc()`, `free()`, `atoi()`, `rand()`, `exit()`
- **`<string.h>`** — String manipulation: `strlen()`, `strcpy()`, `strcmp()`, `strcat()`
- **`<math.h>`** — Mathematics: `sqrt()`, `pow()`, `sin()`, `cos()`, `fabs()`

## Compilation

```bash
cd fundamentals

# Compile with GCC (debug build)
gcc my_headers.h -o my_headers -std=c11 -Wall -Wextra -g

# Run
./my_headers

# Compile with Clang
clang my_headers.h -o my_headers -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc my_headers.h -o my_headers -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`
- **Library header:** `<stdlib.h>`
- **Library header:** `<string.h>`
- **Library header:** `<math.h>`
- **Buggy version:** [`my_headers.h`](my_headers.h) (learn from common mistakes)

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
