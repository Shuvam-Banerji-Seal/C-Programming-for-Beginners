# watchpoint_example.c

> watchpoint_example.c
Example for practicing GDB watchpoints
Learn to track when variables change

## Overview

- **File:** `13-debugging-gdb/watchpoint_example.c`
- **Language:** C source
- **Module:** `13-debugging-gdb`
- **Lines:** 53
- **Libraries:** `stdio.h`

## Concepts

- Standard I/O: `printf`, `scanf` for console input/output
- Pointer operations: declaration, dereferencing (`*`), address-of (`&`), arithmetic

## Functions

### `increment_counter()`

```c
void increment_counter(int amount);
```

### `reset_counter()`

```c
void reset_counter();
```

## Compilation

```bash
cd 13-debugging-gdb
gcc watchpoint_example.c -o watchpoint_example -std=c11 -Wall -Wextra
./watchpoint_example
```
