# recursion_examples.c

> Factorial

## Overview

- **File:** `04-functions/recursion_examples.c`
- **Language:** C source
- **Module:** `04-functions`
- **Lines:** 117
- **Libraries:** `stdio.h`

## Concepts

- Standard I/O: `printf`, `scanf` for console input/output
- Pointer operations: declaration, dereferencing (`*`), address-of (`&`), arithmetic
- Recursion: functions calling themselves with base/termination cases

## Functions

### `factorial()`

```c
int factorial(int n);
```

### `fibonacci()`

```c
int fibonacci(int n);
```

### `sumOfDigits()`

```c
int sumOfDigits(int n);
```

### `power()`

```c
int power(int base, int exp);
```

### `gcd()`

```c
int gcd(int a, int b);
```

### `printBinary()`

```c
void printBinary(int n);
```

### `towerOfHanoi()`

```c
void towerOfHanoi(int n, char from, char to, char aux);
```

### `isPalindrome()`

```c
int isPalindrome(char str[], int start, int end);
```

## Compilation

```bash
cd 04-functions
gcc recursion_examples.c -o recursion_examples -std=c11 -Wall -Wextra
./recursion_examples
```
