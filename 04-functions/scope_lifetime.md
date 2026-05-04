# scope_lifetime.c

> Global variable

## Overview

- **File:** `04-functions/scope_lifetime.c`
- **Language:** C source
- **Module:** `04-functions`
- **Lines:** 99
- **Libraries:** `stdio.h`

## Concepts

- Standard I/O: `printf`, `scanf` for console input/output

## Functions

### `counter()`

```c
void counter();
```

### `localDemo()`

```c
void localDemo();
```

### `modifyGlobal()`

```c
void modifyGlobal();
```

### `shadowDemo()`

```c
void shadowDemo();
```

### `registerDemo()`

```c
void registerDemo();
```

### `blockScope()`

```c
void blockScope();
```

## Compilation

```bash
cd 04-functions
gcc scope_lifetime.c -o scope_lifetime -std=c11 -Wall -Wextra
./scope_lifetime
```
