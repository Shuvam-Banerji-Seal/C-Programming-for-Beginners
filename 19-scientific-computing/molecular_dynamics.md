# molecular_dynamics.c

> Initialize particles

## Overview

- **File:** `19-scientific-computing/molecular_dynamics.c`
- **Language:** C source
- **Module:** `19-scientific-computing`
- **Lines:** 156
- **Libraries:** `stdio.h`, `stdlib.h`, `math.h`, `time.h`

## Concepts

- Standard I/O: `printf`, `scanf` for console input/output
- Standard library: memory allocation (`malloc`/`free`), conversions (`atoi`), exit codes
- Mathematical operations: `sqrt`, `pow`, `sin`, `cos`
- Time/date functions: `time`, `clock`, `srand`/`rand` for randomization
- Pointer operations: declaration, dereferencing (`*`), address-of (`&`), arithmetic
- Structures: defining structs, member access (`.`/`->`), nested structs
- Type aliasing with `typedef` for cleaner type definitions

## Functions

### `initParticles()`

```c
void initParticles(Particle particles[], int n);
```

### `calculateForces()`

```c
void calculateForces(Particle particles[], int n);
```

### `velocityVerlet()`

```c
void velocityVerlet(Particle particles[], int n, double dt);
```

### `calculateKineticEnergy()`

```c
double calculateKineticEnergy(Particle particles[], int n);
```

## Compilation

```bash
cd 19-scientific-computing
gcc molecular_dynamics.c -o molecular_dynamics -std=c11 -Wall -Wextra
./molecular_dynamics
```
