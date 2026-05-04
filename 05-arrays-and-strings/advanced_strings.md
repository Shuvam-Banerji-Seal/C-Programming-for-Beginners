# advanced_strings.c

> advanced_strings.c
Advanced string algorithms and manipulation
Topics: Pattern matching, string tokenization, anagrams, palindromes

## Overview

- **File:** `05-arrays-and-strings/advanced_strings.c`
- **Language:** C source
- **Module:** `05-arrays-and-strings`
- **Lines:** 267
- **Libraries:** `stdio.h`, `string.h`, `ctype.h`, `stdbool.h`

## Concepts

- Standard I/O: `printf`, `scanf` for console input/output
- String manipulation: `strlen`, `strcpy`, `strcmp`, `strcat`
- Pointer operations: declaration, dereferencing (`*`), address-of (`&`), arithmetic

## Functions

### `isPalindrome()`

```c
bool isPalindrome(const char *str);
```

### `areAnagrams()`

```c
bool areAnagrams(const char *str1, const char *str2);
```

### `reverseWords()`

```c
void reverseWords(char *str);
```

### `patternMatch()`

```c
int patternMatch(const char *text, const char *pattern);
```

### `countOccurrences()`

```c
int countOccurrences(const char *text, const char *pattern);
```

### `removeDuplicates()`

```c
void removeDuplicates(char *str);
```

### `longestCommonPrefix()`

```c
void longestCommonPrefix(char *strings[], int count, char *result);
```

### `runLengthEncode()`

```c
void runLengthEncode(const char *str, char *encoded);
```

### `demonstrateTokenization()`

```c
void demonstrateTokenization();
```

## Compilation

```bash
cd 05-arrays-and-strings
gcc advanced_strings.c -o advanced_strings -std=c11 -Wall -Wextra
./advanced_strings
```
