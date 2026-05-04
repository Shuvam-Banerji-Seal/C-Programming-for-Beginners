# compilation_demo.c

> compilation_demo.c
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
- **Language:** C source
- **Module:** `01-basics`
- **Lines:** 34
- **Libraries:** `stdio.h`

## Concepts

- Standard I/O: `printf`, `scanf` for console input/output
- Pointer operations: declaration, dereferencing (`*`), address-of (`&`), arithmetic

## Compilation

```bash
cd 01-basics
gcc compilation_demo.c -o compilation_demo -std=c11 -Wall -Wextra
./compilation_demo
```
