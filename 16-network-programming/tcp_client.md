# `tcp_client.c`

> Create socket

---

## Overview

| Property | Value |
|----------|-------|
| **File** | `16-network-programming/tcp_client.c` |
| **Type** | C source |
| **Module** | `16-network-programming` |
| **Lines** | 71 total (43 code, 7 comments) |
| **Libraries** | `stdio.h`, `stdlib.h`, `string.h`, `unistd.h`, `arpa/inet.h` |
| **Topics** | Tcp Socket |

## What It Does

Implements a TCP client that connects to a server, sends data, and receives responses. Demonstrates `socket()`, `connect()`, `send()`, and `recv()` system calls.

## Program Flow

1. Program execution begins in the `main()` function
2. Uses `printf()` (10 calls) to display output to the console
5. Makes decisions using conditional statements (5 branches)
7. Returns 0 to indicate successful completion

## Key Code Patterns

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void) {
    // ... program logic ...
    return 0;
}
```

## Libraries Used

- **`<stdio.h>`** — Standard I/O: `printf()`, `scanf()`, `fgets()`, `FILE` operations
- **`<stdlib.h>`** — Standard library: `malloc()`, `free()`, `atoi()`, `rand()`, `exit()`
- **`<string.h>`** — String manipulation: `strlen()`, `strcpy()`, `strcmp()`, `strcat()`
- **`<unistd.h>`** — Standard C library
- **`<arpa/inet.h>`** — Standard C library

## Constants & Macros

| Name | Value |
|------|-------|
| `PORT` | Defined in source |
| `BUFFER_SIZE` | Defined in source |

## Compilation

```bash
cd 16-network-programming

# Compile with GCC (debug build)
gcc tcp_client.c -o tcp_client -std=c11 -Wall -Wextra -g

# Run
./tcp_client

# Compile with Clang
clang tcp_client.c -o tcp_client -std=c11 -Wall -Wextra -g

# Compile with address sanitizer (detect memory errors)
gcc tcp_client.c -o tcp_client -std=c11 -Wall -Wextra -fsanitize=address -g
```

## Related Files

- **Module README:** [`../README.md`](../README.md)
- **Module Makefile:** [`../Makefile`](../Makefile)
- **Library header:** `<stdio.h>`
- **Library header:** `<stdlib.h>`
- **Library header:** `<string.h>`
- **Library header:** `<unistd.h>`
- **Library header:** `<arpa/inet.h>`

---

*Part of the [C Programming Course](https://github.com/Shuvam-Banerji-Seal/C-Programming-for-Beginners).*
