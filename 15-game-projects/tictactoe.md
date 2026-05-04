# `tictactoe.c`

> Global board

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `15-game-projects/tictactoe.c` |
| **Type** | C source |
| **Module** | `15-game-projects` |
| **Lines** | 265 total (219 code, 6 comments) |
| **Libraries** | `stdio.h`, `stdlib.h`, `stdbool.h`, `limits.h` |
| **Topics** | Game |

## What It Does

A complete console-based Tic-Tac-Toe game. Demonstrates game state management, player input, win-condition checking, AI move selection, and the game loop pattern.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (36 calls) to display output to the console
3. Uses `scanf()` (5 calls) to read user input
5. Makes decisions using conditional statements (28 branches)
7. Returns 0 to indicate successful completion

## Key Code Patterns

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int main(void) {
    // ... program logic ...
    return 0;
}
```

## Libraries Used

- **`<stdio.h>`** — Standard I/O: `printf()`, `scanf()`, `fgets()`, `FILE` operations
- **`<stdlib.h>`** — Standard library: `malloc()`, `free()`, `atoi()`, `rand()`, `exit()`
- **`<stdbool.h>`** — Boolean type: `bool`, `true`, `false` (C99+)
- **`<limits.h>`** — Integer limits: `INT_MAX`, `LONG_MIN`, `CHAR_BIT`

## Functions

| Function | Returns | Parameters | Purpose |
|----------|---------|------------|---------|
| `initBoard()` | `void` | `` | See implementation for details |
| `printBoard()` | `void` | `` | See implementation for details |
| `isMoveValid()` | `bool` | `int row, int col` | See implementation for details |
| `makeMove()` | `void` | `int row, int col, char player` | See implementation for details |
| `checkWinner()` | `char` | `` | See implementation for details |
| `isBoardFull()` | `bool` | `` | See implementation for details |
| `evaluateBoard()` | `int` | `` | See implementation for details |
| `isMovesLeft()` | `bool` | `` | See implementation for details |
| `minimax()` | `int` | `int depth, bool isMax` | See implementation for details |
| `findBestMove()` | `void` | `` | See implementation for details |
| `playGame()` | `void` | `int mode` | See implementation for details |

## Constants & Macros

| Name | Value |
|------|-------|
| `SIZE` | Defined in source |

## Compilation

```bash
cd 15-game-projects

# Compile with GCC (debug build)
gcc tictactoe.c -o tictactoe -std=c11 -Wall -Wextra -g

# Run
./tictactoe

# Compile with Clang
clang tictactoe.c -o tictactoe -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc tictactoe.c -o tictactoe -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`
- **Library header:** `<stdlib.h>`
- **Library header:** `<stdbool.h>`
- **Library header:** `<limits.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
