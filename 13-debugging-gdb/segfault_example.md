# segfault_example.c

segfault_example.c
Example program that demonstrates common segmentation faults

Use GDB to find and understand the crashes

## Overview

- **File:** `13-debugging-gdb/segfault_example.c`
- **Language:** C
- **Module:** `13-debugging-gdb`

## Key Concepts

This file demonstrates essential C programming concepts including:
- Standard input/output operations using `printf` and `scanf`
- Standard library functions (`malloc`, `free`, `atoi`, etc.)

## Functions

- `example1_null_pointer()`
- `dereference()`
- `example2_buffer_overflow()`
- `printf()`
- `example3_use_after_free()`
- `example4_stack_overflow()`
- `Overflow()`
- `example()`

## Compilation

```bash
# Navigate to the module directory
cd 13-debugging-gdb

# Compile
gcc segfault_example.c -o segfault_example -std=c11 -Wall -Wextra

# Run
./segfault_example
```

## Usage

Run the compiled program to see the demonstrated concepts in action.
