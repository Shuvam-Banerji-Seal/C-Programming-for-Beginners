# `takinh_user_inputs.c`

> void menu() {
printf("1. Compute nPr\n");
printf("2. Compute nCr\n");
printf("3. Exit\n");
}

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `fundamentals/takinh_user_inputs.c` |
| **Type** | C source |
| **Module** | `fundamentals` |
| **Lines** | 35 total (22 code, 7 comments) |
| **Libraries** | `stdio.h` |
| **Topics** | Fundamentals |

## What It Does

Safe user input handling: `scanf()`, `fgets()`, `getchar()`, input validation, buffer overflow prevention, and clearing the input buffer of leftover newlines.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (9 calls) to display output to the console
3. Uses `scanf()` (2 calls) to read user input
5. Makes decisions using conditional statements (3 branches)
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

## Compilation

```bash
cd fundamentals

# Compile with GCC (debug build)
gcc takinh_user_inputs.c -o takinh_user_inputs -std=c11 -Wall -Wextra -g

# Run
./takinh_user_inputs

# Compile with Clang
clang takinh_user_inputs.c -o takinh_user_inputs -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc takinh_user_inputs.c -o takinh_user_inputs -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
