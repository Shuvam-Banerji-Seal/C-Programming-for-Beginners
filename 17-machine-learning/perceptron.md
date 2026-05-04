# `perceptron.c`

> Create perceptron

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `17-machine-learning/perceptron.c` |
| **Type** | C source |
| **Module** | `17-machine-learning` |
| **Lines** | 115 total (78 code, 11 comments) |
| **Libraries** | `stdio.h`, `stdlib.h`, `math.h`, `time.h` |
| **Topics** | Machine Learning, Typedef |

## What It Does

A single-layer perceptron (neural network) implemented from scratch in C. Demonstrates forward propagation, weight updates, activation functions, and training loops — the foundation of modern ML.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (9 calls) to display output to the console
4. Allocates memory dynamically on the heap
5. Makes decisions using conditional statements (3 branches)
7. Returns 0 to indicate successful completion

## Key Code Patterns

```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void) {
    // ... program logic ...
    return 0;
}
```

## Libraries Used

- **`<stdio.h>`** — Standard I/O: `printf()`, `scanf()`, `fgets()`, `FILE` operations
- **`<stdlib.h>`** — Standard library: `malloc()`, `free()`, `atoi()`, `rand()`, `exit()`
- **`<math.h>`** — Mathematics: `sqrt()`, `pow()`, `sin()`, `cos()`, `fabs()`
- **`<time.h>`** — Time: `time()`, `clock()`, `srand()`, `rand()`

## Functions

| Function | Returns | Parameters | Purpose |
|----------|---------|------------|---------|
| `activate()` | `int` | `double sum` | See implementation for details |
| `predict()` | `int` | `Perceptron *p, double *inputs` | See implementation for details |
| `train()` | `void` | `Perceptron *p, double **training_inputs, int *expe...` | See implementation for details |

## Compilation

```bash
cd 17-machine-learning

# Compile with GCC (debug build)
gcc perceptron.c -o perceptron -std=c11 -Wall -Wextra -g

# Run
./perceptron

# Compile with Clang
clang perceptron.c -o perceptron -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc perceptron.c -o perceptron -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`
- **Library header:** `<stdlib.h>`
- **Library header:** `<math.h>`
- **Library header:** `<time.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
