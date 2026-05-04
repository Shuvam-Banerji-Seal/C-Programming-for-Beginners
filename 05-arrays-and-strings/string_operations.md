# string_operations.c

> Custom string length

## Overview

- **File:** `05-arrays-and-strings/string_operations.c`
- **Language:** C source
- **Module:** `05-arrays-and-strings`
- **Lines:** 102
- **Libraries:** `stdio.h`, `string.h`

## Concepts

- Standard I/O: `printf`, `scanf` for console input/output
- String manipulation: `strlen`, `strcpy`, `strcmp`, `strcat`

## Functions

### `myStrLen()`

```c
int myStrLen(char str[]);
```

### `myStrCpy()`

```c
void myStrCpy(char dest[], char src[]);
```

### `myStrCat()`

```c
void myStrCat(char dest[], char src[]);
```

### `myStrCmp()`

```c
int myStrCmp(char str1[], char str2[]);
```

### `reverseString()`

```c
void reverseString(char str[]);
```

### `isPalindrome()`

```c
int isPalindrome(char str[]);
```

## Compilation

```bash
cd 05-arrays-and-strings
gcc string_operations.c -o string_operations -std=c11 -Wall -Wextra
./string_operations
```
