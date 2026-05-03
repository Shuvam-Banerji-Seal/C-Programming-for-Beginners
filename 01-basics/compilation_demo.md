# compilation_demo.c

compilation_demo.c
A program to demonstrate the compilation process

Compile this with:
gcc -E compilation_demo.c -o compilation_demo.i  (preprocessing)
gcc -S compilation_demo.c -o compilation_demo.s  (compilation to assembly)
gcc -c compilation_demo.c -o compilation_demo.o  (assembly to object)
gcc compilation_demo.o -o compilation_demo       (linking)

Or simply:
gcc compilation_demo.c -o compilation_demo

## Overview

- **File:** `01-basics/compilation_demo.c`
- **Language:** C
- **Module:** `01-basics`

## Key Concepts

This file demonstrates essential C programming concepts including:
- Standard input/output operations using `printf` and `scanf`

## Functions

- `compilation_demo()`
- `SQUARE()`

## Compilation

```bash
# Navigate to the module directory
cd 01-basics

# Compile
gcc compilation_demo.c -o compilation_demo -std=c11 -Wall -Wextra

# Run
./compilation_demo
```

## Usage

Run the compiled program to see the demonstrated concepts in action.
