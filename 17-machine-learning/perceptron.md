# perceptron.c

> Create perceptron

## Overview

- **File:** `17-machine-learning/perceptron.c`
- **Language:** C source
- **Module:** `17-machine-learning`
- **Lines:** 115
- **Libraries:** `stdio.h`, `stdlib.h`, `math.h`, `time.h`

## Concepts

- Standard I/O: `printf`, `scanf` for console input/output
- Standard library: memory allocation (`malloc`/`free`), conversions (`atoi`), exit codes
- Mathematical operations: `sqrt`, `pow`, `sin`, `cos`
- Time/date functions: `time`, `clock`, `srand`/`rand` for randomization
- Pointer operations: declaration, dereferencing (`*`), address-of (`&`), arithmetic
- Structures: defining structs, member access (`.`/`->`), nested structs
- Heap memory allocation: `malloc`/`calloc`/`realloc` and `free`
- Type aliasing with `typedef` for cleaner type definitions
- Memory layout analysis using `sizeof` operator

## Functions

### `activate()`

```c
int activate(double sum);
```

### `predict()`

```c
int predict(Perceptron *p, double *inputs);
```

### `train()`

```c
void train(Perceptron *p, double **training_inputs, int *expected_outputs, 
           int num_samples, double learning_rate, int epochs);
```

## Compilation

```bash
cd 17-machine-learning
gcc perceptron.c -o perceptron -std=c11 -Wall -Wextra
./perceptron
```
