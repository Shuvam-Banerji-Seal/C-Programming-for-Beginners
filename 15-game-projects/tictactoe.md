# tictactoe.c

> Global board

## Overview

- **File:** `15-game-projects/tictactoe.c`
- **Language:** C source
- **Module:** `15-game-projects`
- **Lines:** 265
- **Libraries:** `stdio.h`, `stdlib.h`, `stdbool.h`, `limits.h`

## Concepts

- Standard I/O: `printf`, `scanf` for console input/output
- Standard library: memory allocation (`malloc`/`free`), conversions (`atoi`), exit codes

## Functions

### `initBoard()`

```c
void initBoard();
```

### `printBoard()`

```c
void printBoard();
```

### `isMoveValid()`

```c
bool isMoveValid(int row, int col);
```

### `makeMove()`

```c
void makeMove(int row, int col, char player);
```

### `checkWinner()`

```c
char checkWinner();
```

### `isBoardFull()`

```c
bool isBoardFull();
```

### `evaluateBoard()`

```c
int evaluateBoard();
```

### `isMovesLeft()`

```c
bool isMovesLeft();
```

### `minimax()`

```c
int minimax(int depth, bool isMax);
```

### `findBestMove()`

```c
void findBestMove();
```

### `playGame()`

```c
void playGame(int mode);
```

## Compilation

```bash
cd 15-game-projects
gcc tictactoe.c -o tictactoe -std=c11 -Wall -Wextra
./tictactoe
```
