# `molecular_dynamics.c`

> Initialize particles

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `19-scientific-computing/molecular_dynamics.c` |
| **Type** | C source |
| **Module** | `19-scientific-computing` |
| **Lines** | 156 total (113 code, 13 comments) |
| **Libraries** | `stdio.h`, `stdlib.h`, `math.h`, `time.h` |
| **Topics** | Scientific Computing, Typedef |

## What It Does

A molecular dynamics simulation in C. Computes particle interactions using Lennard-Jones potentials, updates positions with velocity Verlet integration, and outputs trajectory data. Demonstrates scientific computing in C.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (10 calls) to display output to the console
5. Makes decisions using conditional statements (5 branches)
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
| `initParticles()` | `void` | `Particle particles[], int n` | See implementation for details |
| `calculateForces()` | `void` | `Particle particles[], int n` | See implementation for details |
| `velocityVerlet()` | `void` | `Particle particles[], int n, double dt` | See implementation for details |
| `calculateKineticEnergy()` | `double` | `Particle particles[], int n` | See implementation for details |

## Constants & Macros

| Name | Value |
|------|-------|
| `NUM_PARTICLES` | Defined in source |
| `BOX_SIZE` | Defined in source |
| `DT` | Defined in source |
| `NUM_STEPS` | Defined in source |
| `MIN_DISTANCE` | Defined in source |

## Compilation

```bash
cd 19-scientific-computing

# Compile with GCC (debug build)
gcc molecular_dynamics.c -o molecular_dynamics -std=c11 -Wall -Wextra -g

# Run
./molecular_dynamics

# Compile with Clang
clang molecular_dynamics.c -o molecular_dynamics -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc molecular_dynamics.c -o molecular_dynamics -std=c11 -Wall -Wextra -fsanitize=address -g
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
