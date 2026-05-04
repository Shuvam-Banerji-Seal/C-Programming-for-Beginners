# file_processing.c

> file_processing.c
File processing and text manipulation
Topics: Line-by-line processing, word counting, search and replace

## Overview

- **File:** `09-file-io/file_processing.c`
- **Language:** C source
- **Module:** `09-file-io`
- **Lines:** 269
- **Libraries:** `stdio.h`, `stdlib.h`, `string.h`, `ctype.h`

## Concepts

- Standard I/O: `printf`, `scanf` for console input/output
- Standard library: memory allocation (`malloc`/`free`), conversions (`atoi`), exit codes
- String manipulation: `strlen`, `strcpy`, `strcmp`, `strcat`
- File I/O: open, read, write, close files in text and binary modes
- Pointer operations: declaration, dereferencing (`*`), address-of (`&`), arithmetic
- Structures: defining structs, member access (`.`/`->`), nested structs
- Heap memory allocation: `malloc`/`calloc`/`realloc` and `free`
- Type aliasing with `typedef` for cleaner type definitions
- Memory layout analysis using `sizeof` operator

## Functions

### `analyzeFile()`

```c
FileStats analyzeFile(const char *filename);
```

### `searchInFile()`

```c
int searchInFile(const char *filename, const char *word);
```

### `replaceInFile()`

```c
void replaceInFile(const char *filename, const char *old_word, const char *new_word);
```

### `reverseFile()`

```c
void reverseFile(const char *filename, const char *output);
```

### `mergeFiles()`

```c
void mergeFiles(const char *file1, const char *file2, const char *output);
```

## Compilation

```bash
cd 09-file-io
gcc file_processing.c -o file_processing -std=c11 -Wall -Wextra
./file_processing
```
