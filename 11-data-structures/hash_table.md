# hash_table.c

> hash_table.c
Hash table implementation with chaining
Topics: Hash functions, collision resolution, load factor

## Overview

- **File:** `11-data-structures/hash_table.c`
- **Language:** C source
- **Module:** `11-data-structures`
- **Lines:** 276
- **Libraries:** `stdio.h`, `stdlib.h`, `string.h`

## Concepts

- Standard I/O: `printf`, `scanf` for console input/output
- Standard library: memory allocation (`malloc`/`free`), conversions (`atoi`), exit codes
- String manipulation: `strlen`, `strcpy`, `strcmp`, `strcat`
- Pointer operations: declaration, dereferencing (`*`), address-of (`&`), arithmetic
- Structures: defining structs, member access (`.`/`->`), nested structs
- Heap memory allocation: `malloc`/`calloc`/`realloc` and `free`
- Type aliasing with `typedef` for cleaner type definitions
- Memory layout analysis using `sizeof` operator

## Functions

### `hash()`

```c
unsigned int hash(const char *str, int table_size);
```

### `insert()`

```c
void insert(HashTable *table, const char *key, int value);
```

### `search()`

```c
int search(HashTable *table, const char *key, int *value);
```

### `delete()`

```c
int delete(HashTable *table, const char *key);
```

### `display()`

```c
void display(HashTable *table);
```

### `loadFactor()`

```c
float loadFactor(HashTable *table);
```

### `countCollisions()`

```c
int countCollisions(HashTable *table);
```

### `freeHashTable()`

```c
void freeHashTable(HashTable *table);
```

## Compilation

```bash
cd 11-data-structures
gcc hash_table.c -o hash_table -std=c11 -Wall -Wextra
./hash_table
```
