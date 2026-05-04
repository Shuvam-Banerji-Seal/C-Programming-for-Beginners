# advanced_file_io.c

> advanced_file_io.c
Advanced file I/O operations
Topics: CSV parsing, structured data I/O, file positioning, error handling

## Overview

- **File:** `09-file-io/advanced_file_io.c`
- **Language:** C source
- **Module:** `09-file-io`
- **Lines:** 288
- **Libraries:** `stdio.h`, `stdlib.h`, `string.h`

## Concepts

- Standard I/O: `printf`, `scanf` for console input/output
- Standard library: memory allocation (`malloc`/`free`), conversions (`atoi`), exit codes
- String manipulation: `strlen`, `strcpy`, `strcmp`, `strcat`
- File I/O: open, read, write, close files in text and binary modes
- Pointer operations: declaration, dereferencing (`*`), address-of (`&`), arithmetic
- Structures: defining structs, member access (`.`/`->`), nested structs
- Type aliasing with `typedef` for cleaner type definitions
- Memory layout analysis using `sizeof` operator

## Functions

### `writeCSV()`

```c
void writeCSV(const char *filename, Student students[], int count);
```

### `readCSV()`

```c
int readCSV(const char *filename, Student students[], int max_count);
```

### `writeBinaryRecords()`

```c
void writeBinaryRecords(const char *filename, Student students[], int count);
```

### `readBinaryRecords()`

```c
int readBinaryRecords(const char *filename, Student students[], int max_count);
```

### `demonstrateFilePositioning()`

```c
void demonstrateFilePositioning(const char *filename);
```

### `appendToCSV()`

```c
void appendToCSV(const char *filename, Student *student);
```

### `countLines()`

```c
int countLines(const char *filename);
```

### `copyFile()`

```c
void copyFile(const char *source, const char *dest);
```

## Compilation

```bash
cd 09-file-io
gcc advanced_file_io.c -o advanced_file_io -std=c11 -Wall -Wextra
./advanced_file_io
```
